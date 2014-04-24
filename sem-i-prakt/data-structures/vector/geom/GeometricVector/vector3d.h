#include "vector.h"
#pragma once
/// Тримерен геометричен вектор - използва за основа двумерен геометричен вектор и допълнителна координата (т. нар. композиция)

class Vector3D
{
    /// Член-данни:
	Vector v; /// двумерен вектор, който съдържа абсцисата (x-координатата) и ординатата (y-координатата) на вектора
	double z; /// апликата (z-координата) на вектора

public:
	/// Методи:
    /// - конструктори - реализират се осем конструктора:
	Vector3D(double = 0.0, double = 0.0, double = 0.0);                                         /// 1. конструктор по подразбиране  - задава на вектора стойност нулевия вектор (0.0, 0.0, 0.0);
                                                                                                /// 2. конструктор с един параметър - инициализира абсцисата с подадения параметър,
                                                                                                ///    а ординатата и апликатата - с 0.0;
                                                                                                /// 3. конструктор с два параметъра - инициализира абсцисата и ординатата
                                                                                                ///    с подадените параметри, а апликатата - с 0.0;
                                                                                                /// 4. конструктор с три параметъра - инициализира абсцисата и ординатата
                                                                                                ///    с първите два параметъра, а апликатата - с третия параметър;
    Vector3D(const Vector&, double = 0.0);                                                      /// 5. конструктор с един параметър - инициализира двумерния подвектор
                                                                                                ///    с подадения параметър, а апликатата - с 0.0;
                                                                                                /// 6. конструктор с два параметъра - инициализира двумерния подвектор
                                                                                                ///    с първия подаден параметър, а апликатата - с втория;
    Vector3D(const Vector3D&);                                                                  /// 7. конструктор за копиране;
    Vector3D& operator=(const Vector3D&);                                                       /// 8. оператор за присвояване.

	/// - селектори:
	double getX() const;								                                        /// селектор, връщащ абсцисата на вектора
	double getY() const;								                                        /// селектор, връщащ ординатата на вектора
	double getZ() const;								                                        /// селектор, връщащ апликатата на вектора
	Vector getV() const;                                                                        /// селектор, връщащ двумерния подвектор
	bool isNull() const;								                                        /// връща дали векторът съвпада с нулевия (true, ако съвпада; false в противен случай)
	double length() const;								                                        /// връща дължината (модула) на вектора

    /// - мутатори:
	void setX(double);									                                        /// мутатор, променящ стойността на абсцисата на вектора
	void setY(double);								                                            /// мутатор, променящ стойността на ординатата на вектора
	void setZ(double);									                                        /// мутатор, променящ стойността на апликатата на вектора
	void setV(const Vector&);                                                                   /// мутатор, променящ стойността на двумерния подвектор
	void setVector(const Vector&, double);                                                      /// променя стойността на двумерния подвектор и апликатата на вектора
	void setVector(double, double, double);                                                     /// задава нови координати на вектора

	/// - операции над вектори:

	/// -- непроменящи вектора:

	/// --- унарни:
    void print() const;		                                                                    /// извежда вектора на стандартния изход във вида (х, у, z)
    Vector3D normalized() const;						                                        /// връща вектора в нормализиран вид (с единична дължина)

    /// --- бинарни:
    bool isEqual(const Vector3D&) const;                                                        /// връща дали векторът е равен на подадения като параметър вектор
    bool isCollinear(const Vector3D&) const;                                                    /// връща дали векторът е колинеарен с подадения като параметър вектор
	Vector3D multipliedByScalar(double) const;                                                  /// връща вектора, мащабиран с число (умножен по числото)
	Vector3D sum(const Vector3D&) const;		                                                /// връща сбора на вектора с подадения като параметър вектор
    Vector3D difference(const Vector3D&) const;                                                 /// връща разликата на вектора с подадения като параметър вектор (изважда от вектора параметъра)
	double scalarProduct(const Vector3D&) const;                                                /// връща скаларното произведение на вектора с подадения като параметър вектор
    Vector3D vectorProduct(const Vector3D&) const;                                              /// връща векторното произведение на вектора с подадения като параметър вектор

    /// --- тернарни:
    bool isOrthonormalCoordinateSystem(const Vector3D&, const Vector3D&) const;                 /// връща дали може да се образува ОКС (ортонормирана координатна ситема) от вектора и подадените като параметри вектори
    double scalarMixedProduct(const Vector3D&, const Vector3D&) const;                          /// връща смесеното произведение на вектора с подадените като параметри вектори (те са в скобите)
    Vector3D vectorMixedProduct(const Vector3D&, const Vector3D&) const;                        /// връща двойното векторно произведение на вектора с подадените като параметри вектори (те са в скобите)

    /// -- променящи вектора:

    /// --- унарни:
    void read();                                                                                /// прочита вектора от стандартния вход (взима три числа за координатите)
	void normalize();									                                        /// нормализира вектора (разделя координатите на дължината му)

    /// --- бинарни:
	Vector3D& multiplyByScalar(double);                                                         /// мащабира вектора с число и връща псевдоним към вектора
	Vector3D& operator*=(double);                                                               /// същото като multiplyByScalar
	Vector3D& add(const Vector3D&);						   	                                    /// събира вектора с подадения като параметър вектор и връща псевдоним към вектора
	Vector3D& operator+=(const Vector3D&);						   	                            /// същото като add
	Vector3D& subtract(const Vector3D&);                                                        /// изважда подадения като параметър вектор от вектора и връща псевдоним към вектора
	Vector3D& operator-=(const Vector3D&);                                                      /// същото като subtract
};

/// Външни функции:
bool areEqual(const Vector3D& v1, const Vector3D& v2);                                          /// връща дали два вектора са равни
bool operator==(const Vector3D& v1, const Vector3D& v2);                                        /// същото като areEqual
bool areCollinear(const Vector3D& v1, const Vector3D& v2);                                      /// връща дали два вектора са колинеарни
bool isOrthonormalCoordinateSystem(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3); /// връща дали може да се образува ОКС (ортонормирана координатна ситема) от три вектора
Vector3D multiplyVectorByScalar(const Vector3D& v, double c);                                   /// връща вектор, мащабиран с число (умножен по числото)
Vector3D operator*(const Vector3D& v, double c);                                                /// същото като multiplyVectorByScalar
Vector3D sum(const Vector3D& v1, const Vector3D& v2);    	                                    /// връща сбора на два вектора
Vector3D operator+(const Vector3D& v1, const Vector3D& v2);    	                                /// същото като sum
Vector3D difference(const Vector3D& v1, const Vector3D& v2);                                    /// връща разликата на два вектора (от първия изважда втория)
Vector3D operator-(const Vector3D& v1, const Vector3D& v2);    	                                /// същото като difference
double scalarProduct(const Vector3D& v1, const Vector3D& v2);                                   /// връща скаларното произведение на два вектора
Vector3D vectorProduct(const Vector3D& v1, const Vector3D& v2);                                 /// връща векторното произведение на два вектора
