#include <iostream>
#include <cmath>
#include "vector3d.h"

/// Конструктори

Vector3D::Vector3D(double x = 0.0, double y = 0.0, double _z = 0.0): v(x, y), z(_z) {}
Vector3D::Vector3D(const Vector& _v, double _z = 0.0): v(_v), z(_z) {}
Vector3D::Vector3D(const Vector3D& _v): v(_v.v), z(_v.z) {}

Vector3D& Vector3D::operator=(const Vector3D& _v)
{
    if (this != &_v)
    {
        v = _v.v;
        z = _v.z;
    }

    return *this;
}

/// Селектори

double Vector3D::getX() const
{
	return v.getX();
}

double Vector3D::getY() const
{
	return v.getY();
}

double Vector3D::getZ() const
{
	return z;
}

Vector Vector3D::getV() const
{
	return v;
}

bool Vector3D::isNull() const
{
	return v.isNull() && getZ() == 0.0;
}

double Vector3D::length() const
{
	return sqrt(getX() * getX() + getY() * getY() + getZ() * getZ());
}

/// Мутатори

void Vector3D::setX(double x)
{
	v.setX(x);
}

void Vector3D::setY(double y)
{
	v.setY(y);
}

void Vector3D::setZ(double _z)
{
	z = _z;
}

void Vector3D::setV(const Vector& _v)
{
	v = _v;
}

void Vector3D::setVector(const Vector& v, double c)
{
    setV(v);
    setZ(c);
}

void Vector3D::setVector(double a, double b, double c)
{
	setX(a);
	setY(b);
	setZ(c);
}

/// Операции
/// - непроменящи
/// -- унарни

void Vector3D::print() const
{
	std::cout << '(' << getX() << ", " << getY() << ", " << getZ() << ')' << std::endl;
}

Vector3D Vector3D::normalized() const
{
	if (!isNull())
	{
		double len = length();
		return Vector3D(getX() / len, getY() / len, getZ() / len);
	}
	else
        return Vector3D();
}

/// -- бинарни

bool Vector3D::isEqual(const Vector3D& v) const
{
    return getV() == v.getV() && getZ() == v.getZ();
}

bool Vector3D::isCollinear(const Vector3D& v) const
{
    return vectorProduct(v).isEqual(Vector3D());
}

Vector3D Vector3D::multipliedByScalar(double c) const
{
    return Vector3D(getV().multipliedByScalar(c), getZ() * c);
}

Vector3D Vector3D::sum(const Vector3D& v) const
{
	return Vector3D(getV().sum(v.getV()), getZ() + v.getZ());
}

Vector3D Vector3D::difference(const Vector3D& v) const
{
	return Vector3D(getV().difference(v.getV()), getZ() - v.getZ());
}

double Vector3D::scalarProduct(const Vector3D& v) const
{
	return getV().scalarProduct(v.getV()) + getZ() * v.getZ();
}

Vector3D Vector3D::vectorProduct(const Vector3D& v) const
{
    return Vector3D(getY() * v.getZ() - getZ() * v.getY(), getZ() * v.getX() - getX() * v.getZ(), getX() * v.getY() - getY() * v.getX());
}

/// -- тернарни

bool Vector3D::isOrthonormalCoordinateSystem(const Vector3D& v1, const Vector3D& v2) const
{
    return scalarProduct(v1) == 0 && v1.scalarProduct(v2) == 0 && scalarProduct(v2) == 0
           && *this == normalized() && v1 == v1.normalized() && v2 == v2.normalized();
}

double Vector3D::scalarMixedProduct(const Vector3D& v1, const Vector3D& v2) const
{
    return scalarProduct(v1.vectorProduct(v2));
}

Vector3D Vector3D::vectorMixedProduct(const Vector3D& v1, const Vector3D& v2) const
{
    return v1.multipliedByScalar(scalarProduct(v2)).difference(v2.multipliedByScalar(scalarProduct(v1)));
}

/// - променящи
/// -- унарни

void Vector3D::read()
{
    v.read();

    double _z;
    std::cin >> _z; if (!std::cin) { std::cerr << "ERROR: Bad input!" << std::endl; return; }
    setZ(_z);
}

void Vector3D::normalize()
{
	if (!isNull())
	{
		double len = length();
		setX(getX() / len);
		setY(getY() / len);
		setZ(getZ() / len);
	}
}

/// -- бинарни

Vector3D& Vector3D::multiplyByScalar(double c)
{
    setV(getV().multipliedByScalar(c));
	setZ(getZ() * c);

	return *this;
}

Vector3D& Vector3D::operator*=(double c)
{
    return multiplyByScalar(c);
}

Vector3D& Vector3D::add(const Vector3D& v)
{
    setV(getV().sum(v.getV()));
	setZ(getZ() + v.getZ());

	return *this;
}

Vector3D& Vector3D::operator+=(const Vector3D& v)
{
    return add(v);
}

Vector3D& Vector3D::subtract(const Vector3D& v)
{
    setV(getV().difference(v.getV()));
	setZ(getZ() - v.getZ());

	return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& v)
{
    return subtract(v);
}

/// Външни функции

bool areEqual(const Vector3D& v1, const Vector3D& v2)
{
    return v1.isEqual(v2);
}

bool operator==(const Vector3D& v1, const Vector3D& v2)
{
    return areEqual(v1, v2);
}

bool areCollinear(const Vector3D& v1, const Vector3D& v2)
{
    return v1.isCollinear(v2);
}

bool isOrthonormalCoordinateSystem(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3)
{
    return v1.isOrthonormalCoordinateSystem(v2, v3);
}

Vector3D multiplyVectorByScalar(const Vector3D& v, double c)
{
    return v.multipliedByScalar(c);
}

Vector3D operator*(const Vector3D& v, double c)
{
    return multiplyVectorByScalar(v, c);
}

Vector3D sum(const Vector3D& v1, const Vector3D& v2)
{
    return v1.sum(v2);
}

Vector3D operator+(const Vector3D& v1, const Vector3D& v2)
{
    return sum(v1, v2);
}

Vector3D difference(const Vector3D& v1, const Vector3D& v2)
{
    return v1.difference(v2);
}

Vector3D operator-(const Vector3D& v1, const Vector3D& v2)
{
    return difference(v1, v2);
}

double scalarProduct(const Vector3D& v1, const Vector3D& v2)
{
    return v1.scalarProduct(v2);
}

Vector3D vectorProduct(const Vector3D& v1, const Vector3D& v2)
{
    return v1.vectorProduct(v2);
}
