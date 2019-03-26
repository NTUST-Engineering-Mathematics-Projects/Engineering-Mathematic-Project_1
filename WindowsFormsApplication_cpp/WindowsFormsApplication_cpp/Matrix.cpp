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
Matrix::Matrix(std::string name, std::vector<std::vector<double>> data)
{
	Name = name;
	Data = data;
}
// OperatorOverLoading
const Matrix & Matrix::operator+(const Matrix & m)
{
	for (unsigned int i = 0; i < this->Data.size(); i++)
	{
		for (unsigned int j = 0; j < this->Data[i].size(); j++)
		{
			this->Data[i][j] += m.Data[i][j];
		}
	}
	return *this;
}
const Matrix & Matrix::operator-(const Matrix & m)
{
	for (unsigned int i = 0; i < this->Data.size(); i++)
	{
		for (unsigned int j = 0; j < this->Data[i].size(); j++)
		{
			this->Data[i][j] -= m.Data[i][j];
		}
	}
	return *this;
}
const Matrix& Matrix::operator*(const Matrix& m)
{
	std::vector<double>RowBuf;
	/*for (unsigned int i = 0;;)
	{

	}*/
	return;
}