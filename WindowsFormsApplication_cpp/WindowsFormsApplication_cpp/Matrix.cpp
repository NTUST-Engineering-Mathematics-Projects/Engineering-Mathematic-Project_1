#include "Matrix.h"
int ExChangeTime;
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
	row = data.size();
	column = data[0].size();
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
	for (int i = 0; i < this->row; i++)
	{
		std::vector<double>ColBuf;
		for (int j = 0; j < m.column; j++)
		{
			double temp = 0.0;
			for (int k = 0; k < this->column; k++)
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
	for (int i = 0; i < this->column; i++)
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
// Gaussian
Matrix Gaussian(Matrix GausMatrix)
{
	ExChangeTime = 0;
	Matrix GaussTemp = GausMatrix;
	for (int cur_row = 0, cur_col = 0; cur_row < GaussTemp.Data.size() && cur_col < GaussTemp.Data[0].size(); cur_row++, cur_col++)
	{
		// Find currentMax
		double CMax = abs(GaussTemp.Data[cur_row][cur_col]);
		int MRow = cur_row;
		for (int i = cur_row + 1; i < GaussTemp.Data.size(); i++)
		{
			if (abs(GaussTemp.Data[i][cur_col]) > CMax)
			{
				CMax = abs(GaussTemp.Data[i][cur_col]);
				MRow = i;
			}
		}
		// Column of MRow are all zero
		if (!CMax)
		{
			cur_row--;
			continue;
		}
		if (MRow != cur_row)
		{
			// ExChange Row
			ExChangeTime++;
			std::vector<double>ExTemp = GaussTemp.Data[cur_row];
			GaussTemp.Data[cur_row] = GaussTemp.Data[MRow];
			GaussTemp.Data[MRow] = ExTemp;
		}
		// Clear all nonzero columns
		for (int i = cur_row + 1; i < GaussTemp.Data.size(); i++)
		{
			if (!GaussTemp.Data[i][cur_col])
			{
				continue;
			}
			double Mult = (GaussTemp.Data[i][cur_col] / GaussTemp.Data[cur_row][cur_col]);
			for (int j = cur_col; j < GaussTemp.Data[0].size(); j++)
			{
				GaussTemp.Data[i][j] -= (Mult * GaussTemp.Data[cur_row][j]);
				if ((GaussTemp.Data[i][j] < 1E-6) && (GaussTemp.Data[i][j]) > -1E-6)
				{
					GaussTemp.Data[i][j] = 0;
				}
			}
		}
	}
	return GaussTemp;
}
// Rank of Matrix
const int Matrix::Rank()
{
	Matrix RankTemp = Gaussian(*this);
	int result = 0;
	// Calculate rank
	for (int i = 0; i < RankTemp.Data.size(); i++)
	{
		bool Rflag = true;
		// If all are zero => zero row
		for (int j = 0; j < RankTemp.Data[0].size(); j++)
		{
			if (RankTemp.Data[i][j])
			{
				Rflag = false;
				break;
			}
		}
		// Is zero row ?
		if (Rflag)
			result++;
		else
			continue;
	}
	result = RankTemp.column - result;
	return result;
}
// Determinant of Matrix
const double Matrix::Determinant()
{
	double determinant = 1.0;
	Matrix DetTemp = Gaussian(*this);
	for (int i = 0; i < DetTemp.row; i++)
	{
		determinant *= DetTemp.Data[i][i];
	}
	determinant *= pow(-1, ExChangeTime);
	return determinant;
}