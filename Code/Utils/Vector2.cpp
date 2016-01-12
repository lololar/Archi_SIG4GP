#include "Vector2.h"

Vector2::Vector2(float x = 0, float y = 0) : _x(x), _y(y)
{
}


Vector2::~Vector2()
{
}

ostream& operator<<(ostream& out, const Vector2& f)
{
	return out << "Vector2( " << f._x << ", " << f._y << " )";
}

ostream& operator<<(ostream& out, const Vector2* f)
{
	return out << "Vector2( " << f->_x << ", " << f->_y << " )";
}

Vector2 Vector2::operator+(Vector2 const& parVector)
{
	return Vector2(_x + parVector._x, _y + parVector._y);
}
Vector2 Vector2::operator+=(Vector2 const& parVector)
{
	_x += parVector._x;
	_y += parVector._y;
	return *this;
}
Vector2 Vector2::operator-(Vector2 const& parVector)
{
	return Vector2(_x - parVector._x, _y - parVector._y);
}
Vector2 Vector2::operator-=(Vector2 const& parVector)
{
	_x -= parVector._x;
	_y -= parVector._y;
	return *this;
}
Vector2 Vector2::operator*(float parScale)
{
	return Vector2(_x * parScale, _y * parScale);
}
Vector2 Vector2::operator/(float parScale)
{
	return Vector2(_x / parScale, _y / parScale);
}
bool Vector2::operator==(Vector2 const& parVector)
{
	return _x == parVector._x && _y == parVector._y;
}
bool Vector2::operator!=(Vector2 const& parVector)
{
	return !(*this == parVector);
}
Vector2 operator*(float parScale, Vector2 const &parVector)
{
	return Vector2(parVector._x * parScale, parVector._y * parScale);
}
Vector2 operator/(float parScale, Vector2 const &parVector)
{
	return Vector2(parVector._x / parScale, parVector._y / parScale);
}

float Vector2::Magnitude() const
{
	return sqrtf(_x * _x + _y * _y);
}
void Vector2::Normalize()
{
	float magnitude = Magnitude();
	_x /= magnitude;
	_y /= magnitude;
}
Vector2 Vector2::ToNormalized()
{
	return *this / Magnitude();
}