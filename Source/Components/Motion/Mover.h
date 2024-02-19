#pragma once
#include "UltraEngine.h"

using namespace UltraEngine;

class Mover : public Component
{
public: 
    Vec3 movementspeed;
    Vec3 rotationspeed;
    bool globalcoords {false};
    
    Mover();

    virtual bool Load(table& properties, shared_ptr<Stream> binstream, shared_ptr<Map> scene, const LoadFlags flags);
    virtual bool Save(table& properties, shared_ptr<Stream> binstream, shared_ptr<Map> scene, const SaveFlags flags);
    virtual void Update();
    virtual std::shared_ptr<Component> Copy();
};