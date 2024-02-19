#pragma once
#include "UltraEngine.h"
#include "Mover.h"

using namespace UltraEngine;

Mover::Mover()
{ 
    name = "Mover";
}

bool Mover::Load(table& properties, shared_ptr<Stream> binstream, shared_ptr<Map> scene, const LoadFlags flags)
{
    if (properties["movementspeed"].is_array() and properties["movementspeed"].size() == 3)
    {            
        movementspeed.x = properties["movementspeed"][0];
        movementspeed.y = properties["movementspeed"][1];
        movementspeed.z = properties["movementspeed"][2];
    }
    if (properties["rotationspeed"].is_array() and properties["rotationspeed"].size() == 3)
    {            
        rotationspeed.x = properties["rotationspeed"][0];
        rotationspeed.y = properties["rotationspeed"][1];
        rotationspeed.z = properties["rotationspeed"][2];
    }
    if (properties["globalcoords"].is_boolean()) globalcoords = properties["globalcoords"];
    return true;
}
	
bool Mover::Save(table& properties, shared_ptr<Stream> binstream, shared_ptr<Map> scene, const SaveFlags flags)
{
    properties["movementspeed"] = {};
    properties["movementspeed"][0] = movementspeed.x;
    properties["movementspeed"][1] = movementspeed.y;
    properties["movementspeed"][2] = movementspeed.z;
    properties["rotationspeed"] = {};
    properties["rotationspeed"][0] = rotationspeed.x;
    properties["rotationspeed"][1] = rotationspeed.y;
    properties["rotationspeed"][2] = rotationspeed.z;
    properties["globalcoords"] = globalcoords;
    return true;
}

void Mover::Update()
{
    auto entity = GetEntity();
    if (globalcoords)
    {
        entity->Translate(movementspeed / 60.0f, true);
    }
    else
    {
        entity->Move(movementspeed / 60.0f);
    }
    entity->Turn(rotationspeed / 60.0f, globalcoords);
}

//This method will work with simple components
shared_ptr<Component> Mover::Copy()
{
    return std::make_shared<Mover>(*this);
}
