#pragma once
#include"Vector2.h"

//enum ColliderTag
//{
//	CIRCLE,
//	BOX
//};

struct Collider
{
public:
	//Box
	Vector2 Corners[4];
	Vector2 normals[4];
	
	////Circle
	//float Radius;
	//Vector2 CenterPoint;
};