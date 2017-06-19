#pragma once
#include "Vector2.h"
#include "GameObject.h"

struct Hit
{
	GameObject* ety;
	Vector2 norm;
	float depth;
};