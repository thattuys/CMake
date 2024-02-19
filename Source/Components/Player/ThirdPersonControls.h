#pragma once
#include "UltraEngine.h"

using namespace UltraEngine;

class ThirdPersonControls : public Component
{
    bool freelookstarted{ false };
	Vec3 freelookmousepos;
	Vec3 freelookrotation;
	Vec2 lookchange;
	shared_ptr<Camera> camera;
	Vec3 currentcameraposition;
	float eyeheight = 1.7f;
	float smoothcameradistance = 0;
	float croucheyeheight = 1.0f;
public:
	float modelangle = 0.0f;
	float followdistance = 2.0f;
	float mousesmoothing = 0.0f;
	float mouselookspeed = 1.0f;
	float movespeed = 1.2f;
	float jumpforce = 8.0f;
	float jumplunge = 1.5f;
	float runspeed = 4.8f;
	
	ThirdPersonControls();

	virtual void Start();
	virtual void Update();
	virtual shared_ptr<Component> Copy();
	virtual bool Load(table& properties, shared_ptr<Stream> binstream, shared_ptr<Map> scene, const LoadFlags flags);
	virtual bool Save(table& properties, shared_ptr<Stream> binstream, shared_ptr<Map> scene, const SaveFlags flags);
};