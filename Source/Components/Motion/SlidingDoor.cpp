#pragma once
#include "UltraEngine.h"
#include "SlidingDoor.h"

using namespace UltraEngine;

SlidingDoor::SlidingDoor()
{ 
    name = "SlidingDoor";
}

void SlidingDoor::Start()
{
    auto entity = GetEntity();
    if (entity->GetMass() == 0.0f) entity->SetMass(10);
    startposition = entity->GetPosition(true);
    auto parent = entity->GetParent();
    joint = CreateSliderJoint(startposition, movement.Normalize(), parent, entity);
    joint->SetMotorSpeed(speed);
    joint->SetMaxForce(maxforce);
}

bool SlidingDoor::EventHook(const Event& e, shared_ptr<Object> extra)
{
    auto door = extra->As<SlidingDoor>();
    door->Close();
    return false;
}

void SlidingDoor::Open()
{
    if (closetimer) closetimer->Stop();
    closetimer = nullptr;
    if (resettime > 0)
    {
        closetimer = CreateTimer(resettime);
        ListenEvent(EVENT_TIMERTICK, closetimer, EventHook, Self());
    }
    auto entity = GetEntity();
    if (openstate) return;
    if (not enabled) return;
    openstate = true;
    joint->SetPose(movement.Length());
    if (opensound) entity->EmitSound(opensound);
    FireOutputs("Open");
}

void SlidingDoor::Close()
{
    auto entity = GetEntity();
    if (closetimer) closetimer->Stop();
    closetimer = nullptr;
    if (not openstate) return;
    openstate = false;
    joint->SetPose(0);
    if (closesound) entity->EmitSound(closesound);
    FireOutputs("Close");
}

void SlidingDoor::Enable()
{
    enabled = true;
}

void SlidingDoor::Disable()
{
    enabled = false;
}

bool SlidingDoor::Load(table& t, shared_ptr<Stream> binstream, shared_ptr<Map> scene, const LoadFlags flags)
{
    auto entity = GetEntity();
    if (t["enabled"].is_boolean()) enabled = t["enabled"];
    if (t["speed"].is_number()) speed = t["speed"];
    if (t["maxforce"].is_number()) maxforce = t["maxforce"];
    if (t["startposition"].is_array() and t["startposition"].size() == 3)
    {
        startposition.x = t["startposition"][0];
        startposition.y = t["startposition"][1];
        startposition.z = t["startposition"][2];
        auto temp = entity->GetPosition(true);
        entity->SetPosition(startposition, true);
        if (entity->GetMass() == 0.0f) entity->SetMass(10);
        joint = CreateSliderJoint(startposition, movement.Normalize(), entity->GetParent(), entity);
        joint->SetMotorSpeed(speed);
        joint->SetMaxForce(maxforce);
        entity->SetPosition(temp, true);
    }
    if (t["movement"].is_array() and t["movement"].size() == 3)
    {
        movement.x = t["movement"][0];
        movement.y = t["movement"][1];
        movement.z = t["movement"][2];
    }
    if (t["resettime"].is_number()) resettime = t["resettime"];
    if (t["opensound"].is_string()) opensound = LoadSound(std::string(t["opensound"]));
    if (t["closesound"].is_string()) closesound = LoadSound(std::string(t["closesound"]));
    if (t["openstate"].is_boolean())
    {
        openstate =  t["openstate"];
        if (openstate)
        {
            Open();
        }
        else
        {
            Close();
        }
    }
	return true;
}

void SlidingDoor::Use(shared_ptr<Component> caller)
{
    if (openstate)
    {
        Close();
    }
    else
    {
        Open();
    }
}

bool SlidingDoor::Save(table& t, shared_ptr<Stream> binstream, shared_ptr<Map> scene, const SaveFlags flags)
{
    t["movement"] = {};
    t["movement"][0] = movement.x;
    t["movement"][1] = movement.y;
    t["movement"][2] = movement.z;
    t["speed"] = speed;
	if (opensound and not opensound->path.empty()) t["opensound"] = opensound->path.ToUtf8String();
    if (closesound and not closesound->path.empty()) t["closesound"] = closesound->path.ToUtf8String();
    t["openstate"] = openstate;
    t["startposition"] = {};
    t["startposition"][0] = startposition.x;
    t["startposition"][1] = startposition.y;
    t["startposition"][2] = startposition.z;
    t["resettime"] = resettime;
    t["maxforce"] = maxforce;
    t["enabled"] = enabled;
    return true;
}

std::any SlidingDoor::CallMethod(shared_ptr<Component> caller, const WString& name, const std::vector<std::any>& args)
{
    if (name == "Open")
    {
        Open();
    }
    else if (name == "Close")
    {
        Close();
    }
    else if (name == "Use")
    {
        Use(caller);
    }
    else if (name == "Enable")
    {
        Enable();
    }
    else if (name == "Disable")
    {
        Disable();
    }
    return false;
}

//This method will work with simple components
shared_ptr<Component> SlidingDoor::Copy()
{
    return std::make_shared<SlidingDoor>(*this);
}
