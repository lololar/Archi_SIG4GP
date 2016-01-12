#pragma once

#define DEFAULT_TIME -100

#include <list>
#include <iostream>

using namespace std;

class Vector2
{
public:
	float _x, _y;

	Vector2(float x, float y);
	~Vector2();

	friend ostream& operator<<(ostream& out, const Vector2& f);

	friend ostream& operator<<(ostream& out, const Vector2* f);

	Vector2 operator+(Vector2 const & parVector);

	Vector2 operator+=(Vector2 const & parVector);

	Vector2 operator-(Vector2 const & parVector);

	Vector2 operator-=(Vector2 const & parVector);

	Vector2 operator*(float parScale);

	Vector2 operator/(float parScale);

	bool operator==(Vector2 const & parVector);

	bool operator!=(Vector2 const & parVector);

	float Magnitude() const;

	void Normalize();

	Vector2 ToNormalized();

};