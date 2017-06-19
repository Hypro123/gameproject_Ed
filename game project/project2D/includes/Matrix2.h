#pragma once
#include"Vector2.h"

#ifdef STATIC_LIB
	#define DLL_MATH
#else 
	#ifdef DLL_EXPORT
		#define DLL_MATH __declspec(dllexport)
	#else
		#define DLL_MATH __declspec(dllimport)
#endif	
#endif
class Matrix2
{
public:
	DLL_MATH Matrix2();
	DLL_MATH Matrix2(float m11, float m12, float m21, float m22);
	DLL_MATH ~Matrix2();
	//operator overloads
	float m[2][2];
	DLL_MATH Vector2 operator*(const Vector2 & vec);
	DLL_MATH Matrix2 operator*(const Matrix2 & otr);
	DLL_MATH Vector2 operator[](int index);
	//Identity matrix check
	DLL_MATH bool isIdentity();
	//works out determinant
	DLL_MATH float Determinant();
	//sets the rotation
	DLL_MATH void setRotate(float offset);

	DLL_MATH operator float*();
};

