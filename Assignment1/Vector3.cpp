#include "Vector3.h"

Vector3::Vector3() : x(0), y(0), z(0) {}

Vector3::Vector3(float X, float Y, float Z) : x(X), y(Y), z(Z) {}

Vector3::Vector3(const Vector3& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

Vector3& Vector3::operator=(const Vector3& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	return *this;
}

Vector3& Vector3::operator+(const Vector3& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

Vector3& Vector3::operator-(const Vector3& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	return *this;
}

Vector3& Vector3::operator*(const float& other)
{
	this->x *= other;
	this->y *= other;
	this->z *= other;
	return *this;
}

bool Vector3::operator==(const Vector3& other) const
{
	return (this->x == other.x && 
		this->y == other.y && 
		this->z == other.z);
}

bool Vector3::operator!=(const Vector3& other) const
{
	return (this->x != other.x || 
		this->y != other.y ||
		this->z != other.z);
}

Vector3 Vector3::lerp(Vector3 start, Vector3 end, float percent)
{
	return (start + (end - start) * percent);
}