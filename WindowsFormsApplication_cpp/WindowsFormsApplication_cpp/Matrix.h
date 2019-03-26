#pragma once
#include <vector>
#include<string>

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
};