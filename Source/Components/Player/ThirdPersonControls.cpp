#pragma once
#include "UltraEngine.h"
#include "ThirdPersonControls.h"

using namespace UltraEngine;

ThirdPersonControls::ThirdPersonControls()
{
	name = "ThirdPersonControls";
}

void ThirdPersonControls::Start()
{
	smoothcameradistance = followdistance;
	auto entity = GetEntity();
	entity->SetPhysicsMode(PHYSICS_PLAYER);
	if (entity->GetMass() == 0.0f) entity->SetMass(78);
	entity->SetCollisionType(COLLISION_PLAYER);
	camera = CreateCamera(entity->GetWorld());
	camera->SetPosition(0, eyeheight, 0);
	camera->SetRotation(0, 0, 0);
	camera->SetFov(70);
	currentcameraposition = camera->GetPosition(true);
	freelookrotation = entity->GetRotation(true);
}

void ThirdPersonControls::Update()
{
	Vec3 movement;
	float jump = 0;
	bool crouch = false;
	auto entity = GetEntity();
	auto window = ActiveWindow();
	bool shiftkey = false;
	bool airborne = entity->GetAirborne();

	if (window)
	{
		shiftkey = window->KeyDown(KEY_SHIFT);
		if (!freelookstarted)
		{
			freelookstarted = true;
			freelookrotation = entity->GetRotation(true);
			freelookmousepos = window->GetMouseAxis();
		}
		auto newmousepos = window->GetMouseAxis();
		lookchange.x = lookchange.x * mousesmoothing + (newmousepos.y - freelookmousepos.y) * 100.0f * mouselookspeed * (1.0f - mousesmoothing);
		lookchange.y = lookchange.y * mousesmoothing + (newmousepos.x - freelookmousepos.x) * 100.0f * mouselookspeed * (1.0f - mousesmoothing);
		if (Abs(lookchange.x) < 0.001f) lookchange.x = 0.0f;
		if (Abs(lookchange.y) < 0.001f) lookchange.y = 0.0f;
		if (lookchange.x != 0.0f or lookchange.y != 0.0f)
		{
			freelookrotation.x += lookchange.x;
			freelookrotation.y += lookchange.y;
			camera->SetRotation(freelookrotation, true);
		}
		freelookmousepos = newmousepos;
		float speed = movespeed;// / 60.0f;
		bool jumpkey = window->KeyHit(KEY_SPACE);
		if (entity->GetAirborne())
		{
			speed *= 0.25f;
		}
		else
		{
			if (shiftkey)
			{
				speed = runspeed;
			}
			else if (window->KeyDown(KEY_CONTROL))
			{
				speed *= 0.5f;
			}
			if (jumpkey)
			{
				jump = jumpforce;
			}
		}
		if (window->KeyDown(KEY_D)) movement.x += speed;
		if (window->KeyDown(KEY_A)) movement.x -= speed;
		if (window->KeyDown(KEY_W)) movement.z += speed;
		if (window->KeyDown(KEY_S)) movement.z -= speed;
		if (movement.x != 0.0f and movement.z != 0.0f) movement *= 0.707f;
		if (jump != 0.0f)
		{
			movement.x *= jumplunge;
			if (movement.z > 0.0f) movement.z *= jumplunge;
		}
		crouch = window->KeyDown(KEY_CONTROL);
	}
	entity->SetInput(camera->rotation.y, movement.z, movement.x, jump, crouch);
		
	float eye = eyeheight;
	float y = currentcameraposition.y - entity->GetPosition(true).y;
	float h = eye;
	if (y < eye) h = Mix(y, eye, 0.5f);
		
	currentcameraposition = entity->GetPosition(true) + Vec3(0, h, 0);
	camera->SetPosition(currentcameraposition, true);

	auto campos = TransformPoint(0, 0, -followdistance, camera, nullptr);

	auto world = entity->GetWorld();
	if (world)
	{
		auto temp = entity->GetPickMode();
		entity->SetPickMode(PICK_NONE);
		auto pickinfo = world->Pick(camera->GetPosition(true), campos, 0.5, true);
		entity->SetPickMode(temp);
		if (pickinfo.entity) campos = pickinfo.position;
		float d = campos.DistanceToPoint(camera->GetPosition(true));
		if (d > smoothcameradistance)
		{
			smoothcameradistance = Mix(d, smoothcameradistance, 0.9f);
		}
		else
		{
			smoothcameradistance = Mix(d, smoothcameradistance, 0.5f);
		}
		campos = TransformPoint(0, 0, -smoothcameradistance, camera, nullptr);
	}
	camera->SetPosition(campos);

	entity->SetRotation(0, freelookrotation.y + modelangle, 0);

	//Animation
	auto model = entity->As<Model>();
	if (not model) return;
	if (not airborne and jump == 0.0f)
	{
		WString sequencename = "idle";
		auto v = entity->GetVelocity();
		if (v.xz().Length() > 0.1)
		{
			sequencename = "walk";
			if (shiftkey) sequencename = "run";				
		}
		model->Animate(sequencename);
	}
	else
	{
		if (jump > 0.0f) model->Animate("jump", 0.1, 250, ANIMATION_ONCE);
	}
}

//This method will work with simple components
shared_ptr<Component> ThirdPersonControls::Copy()
{
	return std::make_shared<ThirdPersonControls>(*this);
}

bool ThirdPersonControls::Load(table& properties, shared_ptr<Stream> binstream, shared_ptr<Map> scene, const LoadFlags flags)
{
	if (properties["runspeed"].is_number()) runspeed = properties["runspeed"];
	if (properties["modelangle"].is_number()) modelangle = properties["modelangle"];
    if (properties["mousesmoothing"].is_number()) mousesmoothing = properties["mousesmoothing"];
    if (properties["mouselookspeed"].is_number()) mouselookspeed = properties["mouselookspeed"];
    if (properties["movespeed"].is_number()) movespeed = properties["movespeed"];
	if (properties["followdistance"].is_number()) followdistance = properties["followdistance"];
	smoothcameradistance = followdistance;
	return true;
}
	
bool ThirdPersonControls::Save(table& properties, shared_ptr<Stream> binstream, shared_ptr<Map> scene, const SaveFlags flags)
{
	properties["runspeed"] = runspeed;
	properties["modelangle"] = modelangle;
	properties["mousesmoothing"] = mousesmoothing;
	properties["mouselookspeed"] = mouselookspeed;
	properties["movespeed"] = movespeed;
	properties["followdistance"] = followdistance;
	return true;
}