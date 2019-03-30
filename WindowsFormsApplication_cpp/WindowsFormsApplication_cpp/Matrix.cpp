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
const int Matrix::Rank()
{
	int result = 0;
	Matrix RankTemp = *this;
	for (int cur_row = 0, cur_col = 0; cur_row < RankTemp.row, cur_col < RankTemp.column; cur_row++, cur_col++)
	{
		// Find currentMax
		double CMax = abs(RankTemp.Data[cur_row][cur_col]);
		int MRow = cur_row;
		for (int i = MRow + 1; i < RankTemp.Data.size(); i++)
		{
			if (abs(RankTemp.Data[i][cur_col]) > CMax)
			{
				CMax = abs(RankTemp.Data[i][cur_col]);
				MRow = i;
			}
		}
		if (MRow != cur_row)
		{
			// Exchange Row
			std::vector<double>ExTemp = RankTemp.Data[MRow];
			RankTemp.Data[MRow] = RankTemp.Data[cur_row];
			RankTemp.Data[cur_row] = ExTemp;
			cur_row--;
			cur_col--;
			continue;
		}
		// Clear all nonzero columns
		for (int i = cur_row + 1; i < RankTemp.row; i++)
		{
			if (RankTemp.Data[i][cur_col] == 0)
			{
				continue;
			}
			double Mult = (RankTemp.Data[i][cur_col] / RankTemp.Data[cur_row][cur_col]);
			for (int j = cur_col; j < RankTemp.column; j++)
			{
				RankTemp.Data[i][j] -= (Mult * RankTemp.Data[cur_row][j]);
				if ((RankTemp.Data[i][j] < 1E-6) && (RankTemp.Data[i][j]) > -1E-6)
					RankTemp.Data[i][j] = 0;
			}
		}
	}
	// Calculate rank
	for (unsigned int i = 0; i < RankTemp.row; i++)
	{
		bool Rflag = true;
		// If all are zero => zero row
		for (unsigned int j = 0; j < RankTemp.column; j++)
		{
			if (RankTemp.Data[i][j] != 0.0)
			{
				Rflag = false;
				break;
			}
		}
		if (Rflag)
			result++;
		else
			continue;
	}
	return result;
}