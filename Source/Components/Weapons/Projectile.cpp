#pragma once
#include "Leadwerks.h"
#include "Projectile.h"

using namespace Leadwerks;

bool Projectile::PickFilter(shared_ptr<Entity> entity, shared_ptr<Object> extra)
{
	return entity != extra;
}

bool Projectile::GetExpired()
{
	return expired;
}
