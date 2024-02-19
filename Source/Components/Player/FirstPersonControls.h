#pragma once
#include "UltraEngine.h"

using namespace UltraEngine;

class FirstPersonControls : public Component
{
    bool freelookstarted{ false };
	Vec3 freelookmousepos;
	Vec3 freelookrotation;
	Vec2 lookchange;
	shared_ptr<Camera> camera;
	Vec3 currentcameraposition;
	float eyeheight = 1.7f;
	float croucheyeheight = 1.0f;
public:
	float mousesmoothing = 0.0f;
	float mouselookspeed = 1.0f;
	float movespeed = 4.0f;
	float jumpforce = 8.0f;
	float jumplunge = 1.5f;
	
	FirstPersonControls();

	virtual void Start();
	virtual void Update();
	virtual shared_ptr<Component> Copy();
	virtual bool Load(table& properties, shared_ptr<Stream> binstream, shared_ptr<Map> scene, const LoadFlags flags);
	virtual bool Save(table& properties, shared_ptr<Stream> binstream, shared_ptr<Map> scene, const SaveFlags flags);
};