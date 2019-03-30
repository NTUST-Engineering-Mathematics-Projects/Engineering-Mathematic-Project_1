#include "Vector.h"

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
const Vector & Vector::operator+(const Vector & v)
{
	for (unsigned int i = 0; i < this->Data.size(); i++)
	{
		this->Data[i] += v.Data[i];
	}
	return *this;
}
const Vector& Vector::operator-(const Vector& v)
{
	for (unsigned int i = 0; i < this->Data.size(); i++)
	{
		this->Data[i] -= v.Data[i];
	}
	return *this;
}
// Dot of Vector
const Vector& Vector::operator*(const Vector & v)
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
const double Vector::norm()
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
const Vector & Vector::normalization()
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