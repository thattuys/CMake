#pragma once
#include "UltraEngine.h"
#include "VRPlayer.h"

using namespace UltraEngine;

VRPlayer::VRPlayer()
{
	name = "VRPlayer";
}

void VRPlayer::Start()
{
	auto entity = GetEntity();
	hmd = GetHmd(entity->GetWorld());
	hmd->SetOffset(entity->GetPosition(true), entity->GetRotation(true));
}

//This method will work with simple components
shared_ptr<Component> VRPlayer::Copy()
{
	return std::make_shared<VRPlayer>(*this);
}