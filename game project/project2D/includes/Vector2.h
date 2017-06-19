#pragma once

#ifdef STATIC_LIB
#define DLL_MATH
#else 
#ifdef DLL_EXPORT
#define DLL_MATH __declspec(dllexport)
#else
#define DLL_MATH __declspec(dllimport)
#endif	
#endif

class Vector2
{
public:
	DLL_MATH Vector2();
	DLL_MATH Vector2(float newX, float newY);
	
	DLL_MATH ~Vector2();
	
	float x, y;
	//operator overloads
	DLL_MATH Vector2 operator+(const Vector2 & pos);
	DLL_MATH Vector2 operator+=(const Vector2 & add);
	DLL_MATH Vector2 operator-(const Vector2 & pos);
	DLL_MATH Vector2 operator-();
	DLL_MATH Vector2 operator-=(const Vector2 & sub);
	DLL_MATH Vector2 operator*(const float & Scalarb);
	DLL_MATH Vector2 operator*=(const float & Multi);
	DLL_MATH Vector2 operator/(const float & Scalar);
	DLL_MATH Vector2 operator/=(const float & Div);
	DLL_MATH float operator[](int index);
	DLL_MATH bool operator<(const Vector2 & pos);
	DLL_MATH bool operator>(const Vector2 & pos);
	DLL_MATH bool operator==(const Vector2 & pos);
	DLL_MATH bool operator!=(const Vector2 & pos);
	DLL_MATH bool operator>=(const Vector2 & pos);
	DLL_MATH bool operator<=(const Vector2 & pos);

	//maximum and minimum movement allowances
	DLL_MATH Vector2 Max(Vector2 max);
	DLL_MATH Vector2 Min(Vector2 Min);
	//distance calculations
	DLL_MATH float Distance(Vector2 pos);
	//normal calculations and bouncing
	DLL_MATH Vector2 CalcNormal(Vector2 pos);
	DLL_MATH Vector2 CalcNormal(Vector2 pos1, Vector2 pos2);
	DLL_MATH Vector2 bounce(Vector2 normal);
	//Lerp and curves
	DLL_MATH Vector2 Lerp(Vector2 A, Vector2 B, float Time);
	DLL_MATH Vector2 BeizerCurve(Vector2 pt1, Vector2 pt2, Vector2 pt3, float percentage);
	DLL_MATH Vector2 hermiteCurve(Vector2 pt1, Vector2 tan1, Vector2 pt2, Vector2 tan2, float percentage);
	DLL_MATH Vector2 CardinalSpline(Vector2 pt1, Vector2 pt2, float percentage);
	DLL_MATH Vector2 Catmull_RomSplines(Vector2 pt1, Vector2 pt2, float percentage);
	//Swizzling
	DLL_MATH Vector2 swizzlingXX();
	DLL_MATH Vector2 swizzlingYY();
	DLL_MATH Vector2 swizzlingXY();
	DLL_MATH Vector2 swizzlingYX();
	//dot product
	DLL_MATH float dot(Vector2 pos);
	DLL_MATH float dot(Vector2 pos1, Vector2 pos2);
	//for circle collider checking
	DLL_MATH float sqrMagnitude();
	//magnitude
	DLL_MATH float Magnitude();
	//clamping
	DLL_MATH void Clamp(Vector2 min, Vector2 max);
	//normalisation
	DLL_MATH void normalise();

	DLL_MATH operator float*();
};

DLL_MATH Vector2 operator*(const float & Scalarf, const Vector2 & pos);
