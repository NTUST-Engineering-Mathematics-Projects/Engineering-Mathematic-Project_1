#pragma once
#include <vector>
#include<string>

//�w�q�V�q��Ƶ��c
struct Vector
{
	std::string Name;
	std::vector<double> Data;
	//�V�q����
	int dimension;
	//Constructors
	Vector::Vector();
	Vector::Vector(double d);
	Vector::Vector(int i);
	Vector::Vector(std::string, std::vector<double>);
	//OperatorOverLoading
	const Vector& operator+(const Vector& v);
	const Vector& operator-(const Vector& v);
	// Multiplication of Vector
	const Vector& Scalar(const Vector& v, const Vector& v2);
	// Dot of Vector
	const double operator*(const Vector& v);
	// Norm of Vector
	const double norm();
	// Normalization of Vector
	const Vector& normalization();
	// Orthogonal judgement
	const bool Orthogonal(const Vector& v);
};