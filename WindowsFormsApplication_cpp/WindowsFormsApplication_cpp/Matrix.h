#pragma once
#include <vector>
#include<string>
#include <iostream>

struct Matrix
{
	std::string Name;
	std::vector<std::vector<double>>Data;
	//¯x°}ºû«×
	int row();
	int column();
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
	Matrix Gaussian(double);
	Matrix Trans();
	Matrix Adjoint();
	Matrix Inverse();
	Matrix Solve(Matrix);
	Matrix LeastSquare(Matrix);
	std::vector<Matrix> Eigen();
	std::vector<Matrix> PM();
};

enum struct Matrix_Error
{
	Row_And_Column_NotEqual,
	Dimension_Error,
	Determinant_Is_Zero,
	Rank_Not_Equal_To_Row,
	Can_Not_Solve,
	Matrix_Size_Out_of_Range,
	Has_No_Such_Matrix,
};

enum struct Vector_Error
{

};