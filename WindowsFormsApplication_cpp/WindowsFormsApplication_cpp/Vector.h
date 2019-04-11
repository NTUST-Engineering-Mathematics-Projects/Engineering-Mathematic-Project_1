#pragma once
#include <vector>
#include<string>

//定義向量資料結構
struct Vector
{
	std::string Name;
	std::vector<double> Data;
	//向量維度
	int dimension();
	//Constructors
	Vector::Vector();
	Vector::Vector(double);
	Vector::Vector(int);
	Vector::Vector(std::string);
	Vector::Vector(std::string, std::vector<double>);
	//OperatorOverLoading
	Vector operator+(Vector&);
	Vector operator-(Vector&);
	// Dot of Vector and Multiplication of Vector
	Vector operator*(Vector&);
	// Norm of Vector
	const double norm();
	// Normalization of Vector
	Vector normalization();
	// Orthogonal judgement
	const bool Orthogonal(Vector&);
	const bool IsZeroVector();
	Vector crossProduct(Vector&);
	const double component(Vector&);
	Vector projection(Vector&);
	const double angle(Vector&);
	const double triangle(Vector&);
	const bool parallel(Vector&);
	Vector PlaneNormal(Vector&);
};

const bool IsLinearIndependent(std::vector<Vector>);
std::vector<Vector> OrthogonalBasis(std::vector<Vector>);
// Vector Error Handling
enum struct Vector_Error
{
	Vector_Error,
	Dimension_Not_Equal,
	Vector_Does_Not_Exist,
	Element_Error,
	One_Or_More_Vector_Are_ZeroVector,
};