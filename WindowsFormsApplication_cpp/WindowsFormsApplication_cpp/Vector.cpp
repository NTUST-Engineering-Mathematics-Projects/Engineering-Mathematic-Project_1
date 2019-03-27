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
// Multiplication of Vector
const Vector& Vector::Scalar(const Vector& v)
{
	std::string Scal = "Scalar";
	std::vector<double>value;
	if (v.Data.size() < this->Data.size())
	{
		for (unsigned int i = 0; i < this->Data.size(); i++)
		{
			value.push_back(this->Data[i] * v.Data[0]);
		}
	}
	else
	{
		for (unsigned int i = 0; i < v.Data.size(); i++)
		{
			value.push_back(v.Data[i] * this->Data[0]);
		}
	}
	return Vector(Scal, value);
}
// Dot of Vector
const double Vector::operator*(const Vector & v)
{
	double dot;
	for (unsigned int i = 0; i < v.Data.size(); i++)
	{
		dot += (v.Data[i] * this->Data[i]);
	}
	return dot;
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
	return ((*this * v) == 0.0) ? true : false;
}