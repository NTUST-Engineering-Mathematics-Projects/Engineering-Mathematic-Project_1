#include "Vector.h"
#include <cmath>

#define PI 3.14159265

// Vector Constructors operation
Vector::Vector()
{}
Vector::Vector(double d)
{
	Data.push_back(d);
}
Vector::Vector(int i)
{
	Data.push_back((double)i);
}
Vector::Vector(std::string name)
{
	Name = name;
}
Vector::Vector(std::string name, std::vector<double> data)
{
	Name = name;
	Data = data;
}
// Vector OperatorOverLoading
const Vector Vector::operator+(const Vector & v)
{
	for (unsigned int i = 0; i < this->Data.size(); i++)
	{
		this->Data[i] += v.Data[i];
	}
	return *this;
}
const Vector Vector::operator-(const Vector& v)
{
	for (unsigned int i = 0; i < this->Data.size(); i++)
	{
		this->Data[i] -= v.Data[i];
	}
	return *this;
}
// Dot of Vector
const Vector Vector::operator*(const Vector & v) const
{
	Vector Result;
	// Multiplication of Vector(Scalar)
	// If size == 1, is scalar.
	if (this->Data.size() == 1)
	{
		for (unsigned int i = 0; i < v.Data.size(); i++)
		{
			double temp = v.Data[i] * this->Data[0];
			Result.Data.push_back(temp);
		}
	}
	else if (v.Data.size() == 1)
	{
		for (unsigned int i = 0; i < this->Data.size(); i++)
		{
			double temp = this->Data[i] * v.Data[0];
			Result.Data.push_back(temp);
		}
	}
	// Dot of Vector
	else
	{
		double dot;
		for (unsigned int i = 0; i < v.Data.size(); i++)
		{
			dot += (v.Data[i] * this->Data[i]);
		}
		Result.Data.push_back(dot);
	}
	return Result;
}
// Norm of Vector
const double Vector::norm() const
{
	double Norm;
	for (unsigned int i = 0; i < this->Data.size(); i++)
	{
		Norm += pow(this->Data[i], 2.0);
	}
	Norm = pow(Norm, 0.5);
	return Norm;
}
// Normalization of Vector
const Vector Vector::normalization()
{
	double N = this->norm();
	for (unsigned int i = 0; i < this->Data.size(); i++)
		this->Data[i] /= N;
	return *this;
}
// Orthogonal judgement
const bool Vector::Orthogonal(const Vector & v)
{
	// Dot of two vectors is 0
	Vector temp = *this * v;
	return (temp.Data[0] == 0.0) ? true : false;
}
// Cross product operating, The plane normal that is produced by two vectors
const Vector Vector::crossProduct(const Vector& v)
{
	Vector answer;
	double i, j, k;
	i = this->Data[1] * v.Data[2] - this->Data[2] * v.Data[1];
	answer.Data.push_back(i);
	j = this->Data[0] * v.Data[2] - this->Data[2] * v.Data[0];
	answer.Data.push_back(j);
	k = this->Data[0] * v.Data[1] - this->Data[1] * v.Data[0];
	answer.Data.push_back(k);
	return answer;
}
//Component of a on b
const double Vector::component(const Vector& v)
{
	return (*this * v).Data[0] / v.norm();
}
//Projection of a on b
const Vector Vector::projection(const Vector& v)
{
	double d1, d2;
	d1 = (*this * v).Data[0];
	d2 = (v * v).Data[0];
	Vector tv = Vector(d1 / d2);
	return tv * v;
}
//Triangle area
const double Vector::triangle(const Vector& v)
{
	double nor = (this->crossProduct(v)).norm();
	return 0.5 * nor;
}
//Parallel judgement
const bool Vector::parallel(const Vector& v)
{
	double dot = (*this * v).Data[0];
	dot = abs(dot);
	if ((dot / v.norm() - this->norm()) < 0.001)
		return true;
	else
		return false;
}
//The angle between two vectors
const double Vector::angle(const Vector& v)
{
	double theta = (*this * v).Data[0] / this->norm() / v.norm();
	double result = acos(theta) * 180.0 / PI;
	return result;
}