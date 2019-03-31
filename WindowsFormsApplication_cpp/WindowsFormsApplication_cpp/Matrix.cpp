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
// Rank of Matrix
const int Matrix::Rank()
{
	Matrix RankTemp = *this;
	int result = 0;
	for (int cur_row = 0, cur_col = 0; cur_row < RankTemp.Data.size() && cur_col < RankTemp.Data[0].size(); cur_row++, cur_col++)
	{
		// Find currentMax
		double CMax = abs(RankTemp.Data[cur_row][cur_col]);
		int MRow = cur_row;
		for (int i = cur_row + 1; i < RankTemp.Data.size(); i++)
		{
			if (abs(RankTemp.Data[i][cur_col]) > CMax)
			{
				CMax = abs(RankTemp.Data[i][cur_col]);
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
			std::vector<double>ExTemp = RankTemp.Data[cur_row];
			RankTemp.Data[cur_row] = RankTemp.Data[MRow];
			RankTemp.Data[MRow] = ExTemp;
		}
		// Clear all nonzero columns
		for (int i = cur_row + 1; i < RankTemp.Data.size(); i++)
		{
			if (!RankTemp.Data[i][cur_col])
			{
				continue;
			}
			double Mult = (RankTemp.Data[i][cur_col] / RankTemp.Data[cur_row][cur_col]);
			for (int j = cur_col; j < RankTemp.Data[0].size(); j++)
			{
				RankTemp.Data[i][j] -= (Mult * RankTemp.Data[cur_row][j]);
				if ((RankTemp.Data[i][j] < 1E-6) && (RankTemp.Data[i][j]) > -1E-6)
					RankTemp.Data[i][j] = 0;
			}
		}
	}
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