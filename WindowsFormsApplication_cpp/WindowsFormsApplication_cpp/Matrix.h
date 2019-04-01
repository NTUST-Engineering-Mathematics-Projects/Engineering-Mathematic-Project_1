#pragma once
#include <vector>
#include<string>
#include <iostream>

struct Matrix
{
	std::string Name;
	std::vector<std::vector<double>>Data;
	//¯x°}ºû«×
	const int row();
	const int column();
	// Constructors
	Matrix();
	Matrix(double d);
	Matrix(int i);
	Matrix(std::string, std::vector<std::vector<double>>);
	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator*(const Matrix&);
	const int Rank();
	const double Determinant();
};
Matrix Gaussian(Matrix);
Matrix Trans(Matrix);
Matrix Adjoint(Matrix);
Matrix Inverse(Matrix);
Matrix Solve(Matrix, Matrix);

enum struct Matrix_Error
{
	Row_And_Column_NotEqual,
	Dimension_Error,
	Determinant_Is_Zero,
	Rank_Not_Equal_To_Row,
	Can_Not_Solve,
};