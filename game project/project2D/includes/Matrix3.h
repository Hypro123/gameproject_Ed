#pragma once
#include"Vector2.h"
#include"Vector3.h"

#ifdef STATIC_LIB
#define DLL_MATH
#else 
#ifdef DLL_EXPORT
#define DLL_MATH __declspec(dllexport)
#else
#define DLL_MATH __declspec(dllimport)
#endif	
#endif

class Matrix3
{
public:
	DLL_MATH Matrix3();
	DLL_MATH Matrix3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33);
	DLL_MATH ~Matrix3();

	float m[3][3];
	//operator overloads
	DLL_MATH Matrix3 operator*(const Matrix3 & otr);
	DLL_MATH Vector3 operator*(const Vector3 & vec);
	DLL_MATH Matrix3 operator*(const float & otr);

	//TRANSFORMATIONS
	DLL_MATH void setRotateX(float offset);
	DLL_MATH void setRotateY(float offset);
	DLL_MATH void setRotateZ(float offset);
	
	DLL_MATH void setRotateDegX(float offset);
	DLL_MATH void setRotateDegY(float offset);
	DLL_MATH void setRotateDegZ(float offset);

	DLL_MATH void setPosition(float xPos, float yPos);
	DLL_MATH void setPosition(Vector2 pos);
	DLL_MATH Vector2 getPosition();
	DLL_MATH void setScale(float Nx, float Ny);
	DLL_MATH void setScale(Vector2 Scale);
	DLL_MATH Vector2 getScale();
	
	//Matrix maths
	//checks for identity matrix
	DLL_MATH bool IsIdentity();
	DLL_MATH float Determinant();
	DLL_MATH Matrix3 Inverse();
	DLL_MATH void Transpose();

	//degrees to radians and vice versa maths
	DLL_MATH float DegreetoRad(float degree);
	DLL_MATH float RadtoDegree(float rad);

	DLL_MATH Vector3& operator[](int index);
	DLL_MATH operator float*();
};

