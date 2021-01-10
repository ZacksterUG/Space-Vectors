#pragma once
#include <math.h>
namespace ZackVector
{
	enum Types
	{
		Degree,
		Radian,
	};
	class Vector
	{
	private:
		float x, y, z;
	public:
		Vector(float x = 0, float y = 0, float z = 0)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		Vector(const Vector& other)
		{
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
		}
		void getPos(float& x, float& y, float& z);
		void setPos(float x, float y, float z);
		float getLength();
		Vector operator=(const Vector& _vec);
		template<typename T> Vector operator*(T scalar);
		float operator*(Vector& _vec);
		bool operator==(Vector& _vec);
		bool operator!=(Vector& _vec);
		template<typename T> Vector operator*=(T scalar);
		Vector operator+=(Vector& _vec);
		Vector operator+(Vector& _vec);
		Vector operator-=(Vector& _vec);
		Vector operator-(Vector& _vec);
		friend Vector crossProd(Vector& _vec1, Vector& _vec2);
		static float vecAngle(Vector& _vec1, Vector& _vec2, Types T);
		static bool collinear(Vector& _vec1, Vector& _vec2);
		static bool coplanar(Vector& _vec1, Vector& _vec2, Vector& _vec3);
	};

	bool Vector::operator==(Vector& _vec)
	{
		if (this->x == _vec.x && this->y == _vec.y && this->z == _vec.z) return true;
		return false;
	}
	bool Vector::operator!=(Vector& _vec)
	{
		if (this->x == _vec.x && this->y == _vec.y && this->z == _vec.z) return false;
		return true;
	}
	Vector Vector::operator=(const Vector& _vec)
	{
		this->x = _vec.x;
		this->y = _vec.y;
		this->z = _vec.z;
		return *this;
	}


	template<typename T> Vector Vector::operator*(T scalar)
	{
		Vector newVect(*this);
		newVect.x *= (float)scalar;
		newVect.y *= (float)scalar;
		newVect.z *= (float)scalar;
		return newVect;
	}
	float Vector::operator*(Vector& _vec)
	{
		return _vec.x * this->x + _vec.y * this->y + _vec.z * this->z;
	}
	template<typename T> Vector Vector::operator*=(T scalar)
	{
		this->x *= (float)scalar;
		this->y *= (float)scalar;
		this->z *= (float)scalar;
		return *this;
	}
	void Vector::getPos(float& x, float& y, float& z)
	{
		x = this->x;
		y = this->y;
		z = this->z;
	}

	void Vector::setPos(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vector Vector::operator+=(Vector& _vec)
	{
		this->x += _vec.x;
		this->y += _vec.y;
		this->z += _vec.z;
		return *this;
	}
	Vector Vector::operator+(Vector& _vec)
	{
		Vector newVect(*this);
		newVect.x += _vec.x;
		newVect.y += _vec.y;
		newVect.z += _vec.z;
		return newVect;
	}

	Vector Vector::operator-=(Vector& _vec)
	{
		this->x -= _vec.x;
		this->y -= _vec.y;
		this->y -= _vec.y;
		return *this;
	}

	Vector Vector::operator-(Vector& _vec)
	{
		Vector newVect(*this);
		newVect.x -= _vec.x;
		newVect.y -= _vec.y;
		newVect.z -= _vec.z;
		return newVect;
	}

	Vector crossProd(Vector& _vec1, Vector& _vec2)
	{
		Vector newVec;
		newVec.x = _vec1.y * _vec2.z - _vec1.z * _vec2.y;
		newVec.y = _vec2.x * _vec1.z - _vec1.x * _vec2.z;
		newVec.z = _vec1.x * _vec2.y - _vec1.y * _vec2.x;
		return newVec;
	}

	float Vector::vecAngle(Vector& _vec1, Vector& _vec2, Types T)
	{
		float curCos = _vec1 * _vec2 / _vec1.getLength() / _vec2.getLength();
		if (T == Types::Radian) return float(acosf(curCos));
		else return float(acosf(curCos) * 180.0 / acosf(-1));
	}

	bool Vector::collinear(Vector& _vec1, Vector& _vec2)
	{
		if (_vec1.x / _vec2.x == _vec1.y / _vec2.y && _vec1.x / _vec2.x == _vec1.z / _vec2.z && _vec1.y / _vec2.y == _vec1.z / _vec2.z) return true;
		return false;
	}

	bool Vector::coplanar(Vector& _vec1, Vector& _vec2, Vector& _vec3)
	{
		float x1, y1, z1, x2, y2, z2, x3, y3, z3;
		_vec1.getPos(x1, y1, z1);
		_vec2.getPos(x2, y2, z2);
		_vec3.getPos(x3, y3, z3);
		if (x1 * (y2 * z3 - z2 * y3) - y1 * (x2 * z3 - z2 * x3) + z1 * (x2 * y3 - y3 * y2) == 0) return true;
		return false;
	}

	float Vector::getLength()
	{
		return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
	}
}
