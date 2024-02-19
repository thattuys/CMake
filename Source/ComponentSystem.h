#pragma once
#include "UltraEngine.h"

#include "Components/Motion/Mover.h"
#include "Components/Motion/SlidingDoor.h"
#include "Components/Player/CameraControls.h"
#include "Components/Player/FirstPersonControls.h"
#include "Components/Player/ThirdPersonControls.h"
#include "Components/Player/VRPlayer.h"
#include "Components/Triggers/CollisionTrigger.h"

void RegisterComponents()
{
    RegisterComponent<Mover>();
    RegisterComponent<SlidingDoor>();
    RegisterComponent<CameraControls>();
    RegisterComponent<FirstPersonControls>();
    RegisterComponent<ThirdPersonControls>();
    RegisterComponent<VRPlayer>();
    RegisterComponent<CollisionTrigger>();
}