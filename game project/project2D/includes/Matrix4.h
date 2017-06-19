#pragma once
#include "Vector4.h"
#include "Vector3.h"

#ifdef STATIC_LIB
#define DLL_MATH
#else 
#ifdef DLL_EXPORT
#define DLL_MATH __declspec(dllexport)
#else
#define DLL_MATH __declspec(dllimport)
#endif	
#endif

class Matrix4
{
public:
	DLL_MATH Matrix4();
	DLL_MATH Matrix4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);
	DLL_MATH ~Matrix4();

	float m[4][4];
	//operator overloads
	DLL_MATH Matrix4 operator*(const Matrix4 & otr);
	DLL_MATH Vector4 operator*(const Vector4 & vec);
	DLL_MATH Matrix4 operator*(const float & otr);
	//TRANSFORMATIONS
	DLL_MATH void setRotateX(float offset);
	DLL_MATH void setRotateY(float offset);
	DLL_MATH void setRotateZ(float offset);
	DLL_MATH void setRotateDegX(float offset);
	DLL_MATH void setRotateDegY(float offset);
	DLL_MATH void setRotateDegZ(float offset);

	DLL_MATH void setPosition(float xPos, float yPos, float zPos);
	DLL_MATH void setPosition(Vector3 pos);
	DLL_MATH Vector3 getPosition();
	DLL_MATH void setScale(float Nx, float Ny, float Nz);
	DLL_MATH void setScale(Vector3 Scale);
	DLL_MATH Vector3 getScale();
	//looking at a particular object
	DLL_MATH void LookAt(Vector3 target, Vector3 pos, Vector3 up);
	//Matrix maths complex
	//checks for identity matrix
	DLL_MATH bool isIdentity();
	DLL_MATH float Determinant();
	DLL_MATH Matrix4 Inverse();
	DLL_MATH void Transpose();
	//degrees to radians and vice versa
	DLL_MATH float DegreetoRad(float degree);
	DLL_MATH float RadtoDegree(float rad);

	DLL_MATH Vector4& operator[](int index);
	DLL_MATH operator float*();
};

