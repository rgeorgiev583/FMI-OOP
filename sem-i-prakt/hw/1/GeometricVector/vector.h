﻿#pragma once
/// Двумерен геометричен вектор - с координати в реални числа

class Vector
{
    /// Член-данни:
	double x, y; /// абсциса и ордината (x- и y-координати) на вектора

public:
    /// Методи:
    /// - конструктори - реализират се пет конструктора:
	Vector(double = 0.0, double = 0.0);			                        /// 1. конструктор по подразбиране  - задава на вектора стойност нулевия вектор;
                                                                        /// 2. конструктор с един параметър - инициализира абсцисата с подадения параметър, а ординатата - с 0.0;
                                                                        /// 3. конструктор с два параметъра - инициализира абсцисата и ординатата с подадените параметри;
    Vector(const Vector&);                                              /// 4. конструктор за копиране;
    Vector& operator=(const Vector&);                                   /// 5. оператор за присвояване.

	/// - селектори:
	double getX() const;						                        /// селектор, връщащ абсцисата на вектора
	double getY() const;						                        /// селектор, връщащ ординатата на вектора
	bool isNull() const;						                        /// връща дали векторът съвпада с нулевия (true, ако съвпада; false в противен случай)
	double length() const;						                        /// връща дължината (модула) на вектора

    /// - мутатори:
	void setX(double);                                                  /// мутатор, променящ стойността на абсцисата на вектора
	void setY(double);                                                  /// мутатор, променящ стойността на ординатата на вектора
	void setVector(double, double);                                     /// задава нови координати на вектора

	/// - операции над вектори:

	/// -- непроменящи вектора:

	/// --- унарни:
    void print() const;                                                 /// извежда вектора на стандартния изход във вида (х, у)
	Vector normalized() const;                                          /// връща вектора в нормализиран вид (с единична дължина)

	/// --- бинарни:
    bool isEqual(const Vector&) const;                                  /// връща дали векторът е равен на подадения като параметър вектор
    bool isCollinear(const Vector&) const;                              /// връща дали векторът е колинеарен с подадения като параметър вектор
    bool isOrthonormalCoordinateSystem(const Vector&) const;            /// връща дали може да се образува ОКС (ортонормирана координатна ситема) от вектора и подадения като параметър вектор
	Vector multipliedByScalar(double) const;                            /// връща вектора, мащабиран с число (умножен по числото)
	Vector sum(const Vector&) const;                                    /// връща сбора на вектора с подадения като параметър вектор
    Vector difference(const Vector&) const;                             /// връща разликата на вектора с подадения като параметър вектор (изважда от вектора параметъра)
	double scalarProduct(const Vector&) const;                          /// връща скаларното произведение на вектора с подадения като параметър вектор

	/// -- променящи вектора:

	/// --- унарни:
	void read();                                                        /// прочита вектора от стандартния вход (взима три числа за координатите)
	void normalize();                                                   /// нормализира вектора (разделя координатите на дължината му)

	/// --- бинарни:
    Vector& multiplyByScalar(double);                                   /// мащабира вектора с число и връща псевдоним към вектора
    Vector& operator*=(double);                                         /// същото като multiplyByScalar
	Vector& add(const Vector&);                                         /// събира вектора с подадения като параметър вектор и връща псевдоним към вектора
	Vector& operator+=(const Vector&);                                  /// същото като add
    Vector& subtract(const Vector&);                                    /// изважда подадения като параметър вектор от вектора и връща псевдоним към вектора
	Vector& operator-=(const Vector&);                                  /// същото като subtract
};

/// Външни функции:
bool areEqual(const Vector& v1, const Vector& v2);                      /// връща дали два вектора са равни
bool operator==(const Vector& v1, const Vector& v2);                    /// същото като areEqual
bool areCollinear(const Vector& v1, const Vector& v2);                  /// връща дали два вектора са колинеарни
bool isOrthonormalCoordinateSystem(const Vector& v1, const Vector& v2); /// връща дали може да се образува ОКС (ортонормирана координатна ситема) от два вектора
Vector multiplyVectorByScalar(const Vector& v, double c);               /// връща вектор, мащабиран с число (умножен по числото)
Vector operator*(const Vector& v, double c);                            /// същото като multiplyVectorByScalar
Vector sum(const Vector& v1, const Vector& v2);                         /// връща сбора на два вектора
Vector operator+(const Vector& v1, const Vector& v2);                   /// същото като sum
Vector difference(const Vector& v1, const Vector& v2);                  /// връща разликата на два вектора (от първия изважда втория)
Vector operator-(const Vector& v1, const Vector& v2);                   /// същото като difference
double scalarProduct(const Vector& v1, const Vector& v2);               /// връща скаларното произведение на два вектора
