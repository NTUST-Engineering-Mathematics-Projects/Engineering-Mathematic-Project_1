#include "Matrix.h"
int ExChangeTime;
// Matrix Constructors operation
Matrix::Matrix()
{}
Matrix::Matrix(double d)
{
	std::vector<double>temp;
	temp.push_back(d);
	Data.push_back(temp);
}
Matrix::Matrix(int i)
{
	std::vector<double>temp;
	temp.push_back((double)i);
	Data.push_back(temp);
}
Matrix::Matrix(std::string name, std::vector<std::vector<double>> data)
{
	Name = name;
	Data = data;
}
const int Matrix::row()
{
	return this->Data.size();
}
const int Matrix::column()
{
	return this->Data[0].size();
}
// OperatorOverLoading
Matrix Matrix::operator+(const Matrix & m)
{
	if (this->Data.size() == m.Data.size() && this->Data[0].size() == m.Data[0].size())
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
	else
		throw Matrix_Error::Dimension_Error;
}
Matrix Matrix::operator-(const Matrix & m)
{
	if (this->Data.size() == m.Data.size() && this->Data[0].size() == m.Data[0].size())
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
	else
		throw Matrix_Error::Dimension_Error;
}
Matrix Matrix::operator*(const Matrix& m)
{
	if (this->Data[0].size() != m.Data.size())
		throw Matrix_Error::Dimension_Error;
	else
	{
		std::string MatMultiple = "MatMultiple";
		std::vector<std::vector<double>>RowBuf;
		for (int i = 0; i < this->row(); i++)
		{
			std::vector<double>ColBuf;
			for (int j = 0; j < m.Data[0].size(); j++)
			{
				double temp = 0.0;
				for (int k = 0; k < this->column(); k++)
				{
					temp += this->Data[i][k] * m.Data[k][j];
				}
				ColBuf.push_back(temp);
			}
			RowBuf.push_back(ColBuf);
		}
		return Matrix(MatMultiple, RowBuf);
	}
}
// Matrix Transpose
Matrix Trans(Matrix T)
{
	Matrix trans;
	trans.Data.clear();
	for (int i = 0; i < T.column(); i++)
	{
		std::vector<double>TrTemp;
		for (unsigned int j = 0; j < T.row(); j++)
		{
			TrTemp.push_back(T.Data[j][i]);
		}
		trans.Data.push_back(TrTemp);
		TrTemp.clear();
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
				if ((GaussTemp.Data[i][j] < 1E-8) && (GaussTemp.Data[i][j]) > -1E-8)
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
	result = RankTemp.column() - result;
	return result;
}
// Determinant of Matrix
const double Matrix::Determinant()
{
	double determinant = 1.0;
	Matrix DetTemp = Gaussian(*this);
	for (int i = 0; i < DetTemp.Data.size(); i++)
	{
		determinant *= DetTemp.Data[i][i];
	}
	determinant *= pow(-1, ExChangeTime);
	return determinant;
}
// Adjint Matrix
Matrix Adjoint(Matrix AdjM)
{
	if (AdjM.row() != AdjM.column())
		throw Matrix_Error::Dimension_Error;
	else
	{
		Matrix AdjMatrix = AdjM;
		Matrix adjTemp;
		// Get Every Cofactor
		for (unsigned int i = 0; i < AdjM.Data.size(); i++)
		{
			for (unsigned int j = 0; j < AdjM.Data[0].size(); j++)
			{
				adjTemp = AdjM;
				// 去除目前位置的Row, Column
				for (unsigned int k = 0; k < AdjM.Data[0].size(); k++)
				{
					if (k != i)
						adjTemp.Data[k].erase(adjTemp.Data[k].begin() + j);
				}
				adjTemp.Data.erase(adjTemp.Data.begin() + i);
				AdjMatrix.Data[i][j] = pow(-1, i + j) * adjTemp.Determinant();
			}
		}
		AdjMatrix = Trans(AdjMatrix);
		return AdjMatrix;
	}
}
// Inverse of Matrix
Matrix Inverse(Matrix InvM)
{
	if ((InvM.Data.size() != InvM.Data[0].size()))
		throw Matrix_Error::Row_And_Column_NotEqual;
	else if ((InvM.Rank() < InvM.Data.size()))
		throw Matrix_Error::Rank_Not_Equal_To_Row;
	else if ((InvM.Determinant() == 0))
		throw Matrix_Error::Determinant_Is_Zero;
	else
	{
		// Inverse(A) = adj(A) * 1/Det(A)
		Matrix InvMatrix = Adjoint(InvM);
		double DetTemp = 1 / InvM.Determinant();
		for (unsigned int i = 0; i < InvMatrix.Data.size(); i++)
		{
			for (unsigned int j = 0; j < InvMatrix.Data[0].size(); j++)
			{
				InvMatrix.Data[i][j] *= DetTemp;
				if (abs(InvMatrix.Data[i][j]) < 1E-6)
					InvMatrix.Data[i][j] = 0;
			}
		}
		return InvMatrix;
	}
}
// Solve Linear System
Matrix Solve(Matrix SM1, Matrix SM2)
{
	if (SM1.column() != SM2.row())
		throw Matrix_Error::Dimension_Error;
	else
	{
		// SM1 has no Adjoint Matrix, Inverse(SM1) doesn't exist
		if (SM1.row() != SM1.column())
			throw Matrix_Error::Can_Not_Solve;
		else
		{
			// Ax = B, Inv(A)Ax = Inv(A)B, x = Inv(A)B
			Matrix InvSM1 = Inverse(SM1);
			Matrix Ans = InvSM1 * SM2;
			return Ans;
		}
	}
}