﻿#include <iostream>
#include <cmath>
#include "vector.h"

/// Конструктори

Vector::Vector(double _x = 0.0, double _y = 0.0): x(_x), y(_y) {}
Vector::Vector(const Vector& v): x(v.x), y(v.y) {}

Vector& Vector::operator=(const Vector& v)
{
    if (this != &v)
    {
        x = v.x;
        y = v.y;
    }

    return *this;
}

/// Селектори

double Vector::getX() const
{
	return x;
}

double Vector::getY() const
{
	return y;
}

bool Vector::isNull() const
{
	return getX() == 0.0 && getY() == 0.0;
}

double Vector::length() const
{
	return sqrt(getX() * getX() + getY() * getY());
}

/// Мутатори

void Vector::setX(double _x)
{
	x = _x;
}

void Vector::setY(double _y)
{
	y = _y;
}

void Vector::setVector(double a, double b)
{
	setX(a);
	setY(b);
}

/// Операции
/// - непроменящи
/// -- унарни

void Vector::print() const
{
	std::cout << '(' << getX() << ", " << getY() << ')' << std::endl;
}

Vector Vector::normalized() const
{
	if (!isNull())
	{
		double len = length();
		return Vector(getX() / len, getY() / len);
	}
	else
        return Vector();
}

/// -- бинарни

bool Vector::isEqual(const Vector& v) const
{
    return getX() == v.getX() && getY() == v.getY();
}

bool Vector::isCollinear(const Vector& v) const
{
    return getX() * v.getY() - getY() * v.getX() == 0;
}

bool Vector::isOrthonormalCoordinateSystem(const Vector& v) const
{
    return scalarProduct(v) == 0 && *this == normalized() && v == v.normalized();
}

Vector Vector::multipliedByScalar(double c) const
{
    return Vector(getX() * c, getY() * c);
}

Vector Vector::sum(const Vector& v) const
{
	return Vector(getX() + v.getX(), getY() + v.getY());
}

Vector Vector::difference(const Vector& v) const
{
	return Vector(getX() - v.getX(), getY() - v.getY());
}

double Vector::scalarProduct(const Vector& v) const
{
	return getX() * v.getX() + getY() * v.getY();
}

/// - променящи
/// -- унарни

void Vector::read()
{
    double _x, _y;
    std::cin >> _x >> _y; if (!std::cin) { std::cerr << "ERROR: Bad input!" << std::endl; return; }
    setX(_x);
    setY(_y);
}

void Vector::normalize()
{
	if (!isNull())
	{
		double len = length();
		setX(getX() / len);
		setY(getY() / len);
	}
}

/// -- бинарни

Vector& Vector::multiplyByScalar(double c)
{
	setX(getX() * c);
	setY(getY() * c);

	return *this;
}

Vector& Vector::operator*=(double c)
{
    return multiplyByScalar(c);
}

Vector& Vector::add(const Vector& v)
{
	setX(getX() + v.getX());
	setY(getY() + v.getY());

	return *this;
}

Vector& Vector::operator+=(const Vector& v)
{
    return add(v);
}

Vector& Vector::subtract(const Vector& v)
{
    setX(getX() - v.getX());
    setY(getY() - v.getY());

	return *this;
}

Vector& Vector::operator-=(const Vector& v)
{
    return subtract(v);
}

/// Външни функции

bool areEqual(const Vector& v1, const Vector& v2)
{
    return v1.isEqual(v2);
}

bool operator==(const Vector& v1, const Vector& v2)
{
    return areEqual(v1, v2);
}

bool areCollinear(const Vector& v1, const Vector& v2)
{
    return v1.isCollinear(v2);
}

bool isOrthonormalCoordinateSystem(const Vector& v1, const Vector& v2)
{
    return v1.isOrthonormalCoordinateSystem(v2);
}

Vector multiplyVectorByScalar(const Vector& v, double c)
{
    return v.multipliedByScalar(c);
}

Vector operator*(const Vector& v, double c)
{
    return multiplyVectorByScalar(v, c);
}

Vector sum(const Vector& v1, const Vector& v2)
{
    return v1.sum(v2);
}

Vector operator+(const Vector& v1, const Vector& v2)
{
    return sum(v1, v2);
}

Vector difference(const Vector& v1, const Vector& v2)
{
    return v1.difference(v2);
}

Vector operator-(const Vector& v1, const Vector& v2)
{
    return difference(v1, v2);
}

double scalarProduct(const Vector& v1, const Vector& v2)
{
    return v1.scalarProduct(v2);
}
