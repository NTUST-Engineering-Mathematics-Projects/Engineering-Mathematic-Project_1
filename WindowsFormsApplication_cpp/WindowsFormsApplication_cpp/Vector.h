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
<<<<<<< HEAD
	Vector operator+(Vector&);
	Vector operator-(Vector&);
	// Dot of Vector and Multiplication of Vector
	Vector operator*(Vector&);
=======
	const Vector operator+(const Vector& v);
	const Vector operator-(const Vector& v);
	// Dot of Vector and Multiplication of Vector
	const Vector operator*(const Vector& v) const;
>>>>>>> 060fbe893691f3477add16eea019b91e64dc5fa3
	// Norm of Vector
	const double norm() const;
	// Normalization of Vector
<<<<<<< HEAD
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
=======
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
>>>>>>> 060fbe893691f3477add16eea019b91e64dc5fa3
};