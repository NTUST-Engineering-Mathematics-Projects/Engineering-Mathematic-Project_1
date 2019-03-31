#pragma once
#include <vector>
#include<string>
#include <iostream>

struct Matrix
{
	std::string Name;
	std::vector<std::vector<double>>Data;
	//¯x°}ºû«×
	int row;
	int column;
	// Constructors
	Matrix();
	Matrix(double d);
	Matrix(int i);
	Matrix(std::string, std::vector<std::vector<double>>);
	const Matrix& operator+(const Matrix&);
	const Matrix& operator-(const Matrix&);
	const Matrix& operator*(const Matrix&);
	const Matrix& Trans();
	const int Rank();
	const double Determinant();
};
Matrix Gaussian(Matrix);