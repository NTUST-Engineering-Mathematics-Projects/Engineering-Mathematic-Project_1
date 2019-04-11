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
	const Vector operator+(const Vector& v);
	const Vector operator-(const Vector& v);
	// Dot of Vector and Multiplication of Vector
	const Vector operator*(const Vector& v) const;
	// Norm of Vector
	const double norm() const;
	// Normalization of Vector
	const Vector normalization();
	// Orthogonal judgement
	const bool Orthogonal(const Vector& v);
	// Cross product operating, The plane normal that is produced by two vectors
	const Vector crossProduct(const Vector& v);
	//Component of a on b
	const double component(const Vector& v);
	//Projection of a on b
	const Vector projection(const Vector& v);
	//Triangle area
	const double triangle(const Vector& v);
	//Parallel judgement
	const bool parallel(const Vector& v);
	//The angle between two vectors
	const double angle(const Vector& v);
};

enum struct Vector_Error
{
	Has_No_Such_Vector
};