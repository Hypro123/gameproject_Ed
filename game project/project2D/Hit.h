#pragma once
#include "Vector2.h"
#include "GameObject.h"

//A struct with everythin that needs to be returned from a collision
struct Hit
{
	//ety = entity
	GameObject* ety;
	Vector2 norm;
	float depth;
};