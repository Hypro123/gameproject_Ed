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

class Vector3
{
public:
	DLL_MATH Vector3();
	DLL_MATH Vector3(float newX, float newY, float newZ);
	DLL_MATH ~Vector3();

	float x, y, z;
	//operator overloads
	DLL_MATH Vector3 operator+(const Vector3 & pos);
	DLL_MATH Vector3 operator+=(const Vector3 & add);
	DLL_MATH Vector3 operator-(const Vector3 & pos);
	DLL_MATH Vector3 operator-();
	DLL_MATH Vector3 operator-=(const Vector3 & sub);
	DLL_MATH Vector3 operator*(const float & Scalarb);
	DLL_MATH Vector3 operator*=(const float & Multi);
	DLL_MATH Vector3 operator/(const float & Scalar);
	DLL_MATH Vector3 operator/=(const float & Div);
	DLL_MATH operator float*();
	DLL_MATH bool operator==(const Vector3 & pos);
	DLL_MATH bool operator!=(const Vector3 & pos);
	DLL_MATH bool operator>=(const Vector3 & pos);
	DLL_MATH bool operator<=(const Vector3 & pos);

	//creating the normals
	DLL_MATH Vector3 CalcNormal(Vector3 pos1, Vector3 pos2);
	//maximum and minimum for movement restrictions
	DLL_MATH Vector3 Max(Vector3 max);
	DLL_MATH Vector3 Min(Vector3 Min);
	//dot product
	DLL_MATH float dot(Vector3 pos);
	//clamping one object to another
	DLL_MATH void Clamp(Vector3 min, Vector3 max);
	//Lerp and curves
	DLL_MATH Vector3 Lerp(Vector3 A, Vector3 B, float Percentage);
	DLL_MATH Vector3 BeizerCurve(Vector3 pt1, Vector3 pt2, Vector3 pt3, float percentage);
	DLL_MATH Vector3 hermiteCurve(Vector3 pt1, Vector3 tan1, Vector3 pt2, Vector3 tan2, float percentage);
	DLL_MATH Vector3 CardinalSpline(Vector3 pt1, Vector3 pt2, float percentage);
	DLL_MATH Vector3 Catmull_RomSplines(Vector3 pt1, Vector3 pt2, float percentage);
	//distance calculations
	DLL_MATH float Distance(Vector3 pos);
	//magnitude
	DLL_MATH float Magnitude();
	//for circle calc fake magnitude
	DLL_MATH float sqrMagnitude();
	//normalisation
	DLL_MATH void normalise();
	//cross products
	DLL_MATH Vector3 cross(Vector3 pos);
	//swizzling
	DLL_MATH Vector3 swizzlingXXX();
	DLL_MATH Vector3 swizzlingXXY();
	DLL_MATH Vector3 swizzlingXXZ();
	DLL_MATH Vector3 swizzlingXYX();
	DLL_MATH Vector3 swizzlingXYY();
	DLL_MATH Vector3 swizzlingXZX();
	DLL_MATH Vector3 swizzlingXZY();
	DLL_MATH Vector3 swizzlingXZZ();
	DLL_MATH Vector3 swizzlingYXX();
	DLL_MATH Vector3 swizzlingYXY();
	DLL_MATH Vector3 swizzlingYXZ();
	DLL_MATH Vector3 swizzlingYYX();
	DLL_MATH Vector3 swizzlingYYY();
	DLL_MATH Vector3 swizzlingYYZ();
	DLL_MATH Vector3 swizzlingYZX();
	DLL_MATH Vector3 swizzlingYZY();
	DLL_MATH Vector3 swizzlingYZZ();
	DLL_MATH Vector3 swizzlingZXX();
	DLL_MATH Vector3 swizzlingZXY();
	DLL_MATH Vector3 swizzlingZXZ();
	DLL_MATH Vector3 swizzlingZYX();
	DLL_MATH Vector3 swizzlingZYY();
	DLL_MATH Vector3 swizzlingZYZ();
	DLL_MATH Vector3 swizzlingZZX();
	DLL_MATH Vector3 swizzlingZZY();
	DLL_MATH Vector3 swizzlingZZZ();
};

DLL_MATH Vector3 operator*(const float & Scalarf, const Vector3 & pos);