#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3();
	Vector3(float X, float Y, float Z);

	Vector3(const Vector3& other);

	Vector3& operator=(const Vector3& other);
	Vector3& operator+(const Vector3& other);
	Vector3& operator-(const Vector3& other);
	Vector3& operator*(const float& other);
	bool operator==(const Vector3& other) const;
	bool operator!=(const Vector3& other) const;
	
	static Vector3 lerp(Vector3 start, Vector3 end, float percent);
};

#endif