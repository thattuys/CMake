#pragma once
#include "UltraEngine.h"

using namespace UltraEngine;

class SlidingDoor : public Component
{
    bool enabled = true;
    bool openstate = false;
    shared_ptr<Joint> joint;
    Vec3 movement = Vec3(0,2,0);
    Vec3 startposition;
    shared_ptr<Timer> closetimer;
    float speed = 1.0f;
    float maxforce = 1000;
    float distancetolerance = 0.1f;
    int resettime = 1000 * 5;
    shared_ptr<Sound> opensound, closesound;
public:

    SlidingDoor();

    virtual void Start();
    static bool EventHook(const Event& e, shared_ptr<Object> extra);
    virtual void Open();
    virtual void Close();
    virtual void Enable();
    virtual void Disable();
    virtual bool Load(table& t, shared_ptr<Stream> binstream, shared_ptr<Map> scene, const LoadFlags flags);
    virtual void Use(shared_ptr<Component> caller);
    virtual bool Save(table& t, shared_ptr<Stream> binstream, shared_ptr<Map> scene, const SaveFlags flags);
    virtual std::any CallMethod(shared_ptr<Component> caller, const WString& name, const std::vector<std::any>& args);
    virtual shared_ptr<Component> Copy();
};