#include "Matrix.h"

// Matrix Constructors operation
Matrix::Matrix()
{}
Matrix::Matrix(double d)
{
	std::vector<double>temp;
	row = 1;
	column = 1;
	temp.push_back(d);
	Data.push_back(temp);
}
Matrix::Matrix(int i)
{
	std::vector<double>temp;
	row = 1;
	column = 1;
	temp.push_back((double)i);
	Data.push_back(temp);
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
	std::string MatMultiple = "MatMultiple";
	std::vector<std::vector<double>>RowBuf;
	for (unsigned int i = 0; i < this->row; i++)
	{
		std::vector<double>ColBuf;
		for (unsigned int j = 0; j < m.column; j++)
		{
			double temp = 0.0;
			for (unsigned int k = 0; k < this->column; k++)
			{
				temp += this->Data[i][k] * m.Data[k][j];
			}
			ColBuf.push_back(temp);
		}
		RowBuf.push_back(ColBuf);
	}
	return Matrix(MatMultiple, RowBuf);
}
// Matrix Transpose
const Matrix & Matrix::Trans()
{
	Matrix trans;
	trans.Name = "MatTranspose";
	trans.row = this->column;
	trans.column = this->row;
	for (unsigned int i = 0; i < this->column; i++)
	{
		std::vector<double>TranBuf;
		for (unsigned int j = 0; this->row; j++)
		{
			TranBuf.push_back(this->Data[j][i]);
		}
		trans.Data.push_back(TranBuf);
	}
	return trans;
}
