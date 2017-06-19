#pragma once
#include"Vector2.h"
#include"Vector3.h"
#include"Vector4.h"

template<class D, class S>
static D CastTo(S source) {};

//VECTOR2 TO VECTOR3
template<>
static Vector2 CastTo(Vector3 source)
{
	Vector2 res;
	res.x = source.x;
	res.y = source.y;

	return res;
};

//VECTOR3 TO VECTOR4
template<>
static Vector3 CastTo(Vector4 source)
{
	Vector3 res;
	res.x = source.x;
	res.y = source.y;
	res.z = source.z;

	return res;
};

//VECTOR4 TO VECTOR2
template<>
static Vector4 CastTo(Vector2 source)
{
	Vector4 res;
	res.x = source.x;
	res.y = source.y;

	return res;
};

//VECTOR3 TO VECTOR2
template<>
static Vector3 CastTo(Vector2 source)
{
	Vector3 res;
	res.x = source.x;
	res.y = source.y;

	return res;
};

//VECTOR4 TO VECTOR3
template<>
static Vector4 CastTo(Vector3 source)
{
	Vector4 res;
	res.x = source.x;
	res.y = source.y;
	res.z = source.z;

	return res;
};