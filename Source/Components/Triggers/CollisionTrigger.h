#pragma once
#include "UltraEngine.h"

using namespace UltraEngine;

class CollisionTrigger : public Component
{
    bool once = false;
    bool enabled = true;
public: 

    CollisionTrigger();

    virtual void Start();
    virtual void Collide(shared_ptr<Entity> collidedentity, const Vec3& position, const Vec3& normal, const float speed);
    virtual void Disable();
    virtual void Enable();
    virtual bool Load(table& t, shared_ptr<Stream> binstream, shared_ptr<Map> scene, const LoadFlags flags);
    virtual bool Save(table& t, shared_ptr<Stream> binstream, shared_ptr<Map> scene, const SaveFlags flags);
    virtual std::any CallMethod(shared_ptr<Component> caller, const WString& name, const std::vector<std::any>& args);
    virtual shared_ptr<Component> Copy();
};