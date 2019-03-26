#include "Matrix.h"

// Matrix Constructors operation
Matrix::Matrix()
{}
Matrix::Matrix(double d)
{
	std::vector<double>temp;
	temp.push_back(d);
	this->Data.push_back(temp);
}
Matrix::Matrix(int i)
{
	std::vector<double>temp;
	temp.push_back((double)i);
	this->Data.push_back(temp);
}