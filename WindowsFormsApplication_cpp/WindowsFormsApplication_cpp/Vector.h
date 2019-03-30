#pragma once
#include <vector>
#include<string>

//定義向量資料結構
struct Vector
{
	std::string Name;
	std::vector<double> Data;
	//向量維度
	int dimension;
	//Constructors
	Vector::Vector();
	Vector::Vector(double d);
	Vector::Vector(int i);
	Vector::Vector(std::string);
	Vector::Vector(std::string, std::vector<double>);
	//OperatorOverLoading
	const Vector& operator+(const Vector& v);
	const Vector& operator-(const Vector& v);
	// Dot of Vector and Multiplication of Vector
	const Vector& operator*(const Vector& v);
	// Norm of Vector
	const double norm();
	// Normalization of Vector
	const Vector& normalization();
	// Orthogonal judgement
	const bool Orthogonal(const Vector& v);
};