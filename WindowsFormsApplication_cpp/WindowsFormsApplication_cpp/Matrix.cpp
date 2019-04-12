#include "Matrix.h"
#define _USE_MATH_DEFINES
#include <math.h>

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
int Matrix::row()
{
	return this->Data.size();
}
int Matrix::column()
{
	return this->Data[0].size();
}
// OperatorOverLoading
Matrix Matrix::operator+(Matrix& m)
{
	if (this->IsZeroM())
		return m;
	else if (m.IsZeroM())
		return *this;
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
Matrix Matrix::operator-(Matrix & m)
{
	if (m.IsZeroM())
		return *this;
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
Matrix Matrix::operator*(Matrix& m)
{
	if (m.IsZeroM() || this->IsZeroM())
		throw Matrix_Error::Zero_Matrix;
	if (this->Data[0].size() != m.Data.size())
		throw Matrix_Error::Dimension_Error;
	else
	{
		Matrix Mul;
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
			Mul.Data.push_back(ColBuf);
		}
		return Mul;
	}
}
// Matrix Transpose
Matrix Matrix::Trans()
{
	Matrix trans;
	trans.Data.clear();
	for (int i = 0; i < this->column(); i++)
	{
		std::vector<double>TrTemp;
		for (unsigned int j = 0; j < this->row(); j++)
		{
			TrTemp.push_back(this->Data[j][i]);
		}
		trans.Data.push_back(TrTemp);
		TrTemp.clear();
	}
	return trans;
}
// Gaussian
Matrix Matrix::Gaussian(double tolerance)
{
	ExChangeTime = 0;
	Matrix GaussTemp = *this;
	for (unsigned int cur_row = 0, cur_col = 0; cur_row < GaussTemp.row() && cur_col < GaussTemp.column(); cur_row++, cur_col++)
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
			std::vector<double> buf = GaussTemp.Data[MRow];
			GaussTemp.Data[MRow] = GaussTemp.Data[cur_row];
			GaussTemp.Data[cur_row] = buf;
		}
		// Clear all nonzero columns
		for (int i = cur_row + 1; i < GaussTemp.Data.size(); i++)
		{
			if (GaussTemp.Data[i][cur_col] == 0)
			{
				continue;
			}
			double sub = GaussTemp.Data[i][cur_col] / GaussTemp.Data[cur_row][cur_col];
			for (int j = cur_col + 1; j < GaussTemp.Data[0].size(); j++)
			{
				GaussTemp.Data[i][j] -= (sub * GaussTemp.Data[cur_row][j]);
			}
			GaussTemp.Data[i][cur_col] = 0;
		}
	}
	// Compare with tolerant
	for (unsigned int i = 0; i < GaussTemp.row(); i++)
	{
		for (unsigned int j = 0; j < GaussTemp.column(); j++)
		{
			if (abs(GaussTemp.Data[i][j]) < tolerance)
				GaussTemp.Data[i][j] = 0;
		}
	}
	return GaussTemp;
}
// Rank of Matrix
const int Matrix::Rank()
{
	Matrix RankTemp = this->Gaussian(1E-6);
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
	Matrix DetTemp = this->Gaussian(1E-6);
	for (int i = 0; i < DetTemp.Data.size(); i++)
	{
		determinant *= DetTemp.Data[i][i];
	}
	determinant *= pow(-1, ExChangeTime);
	return determinant;
}
// Adjint Matrix
Matrix Matrix::Adjoint()
{
	if (this->row() != this->column())
		throw Matrix_Error::Dimension_Error;
	else
	{
		Matrix AdjMatrix = *this;
		Matrix adjTemp;
		// Get Every Cofactor
		for (unsigned int i = 0; i < this->Data.size(); i++)
		{
			for (unsigned int j = 0; j < this->Data[0].size(); j++)
			{
				adjTemp = *this;
				// 去除目前位置的Row, Column
				for (unsigned int k = 0; k < this->Data[0].size(); k++)
				{
					if (k != i)
						adjTemp.Data[k].erase(adjTemp.Data[k].begin() + j);
				}
				adjTemp.Data.erase(adjTemp.Data.begin() + i);
				AdjMatrix.Data[i][j] = pow(-1, i + j) * adjTemp.Determinant();
			}
		}
		AdjMatrix = AdjMatrix.Trans();
		return AdjMatrix;
	}
}
// Inverse of Matrix
Matrix Matrix::Inverse()
{
	if ((this->Data.size() != this->Data[0].size()))
		throw Matrix_Error::Row_And_Column_NotEqual;
	else if ((this->Rank() < this->Data.size()))
		throw Matrix_Error::Rank_Not_Equal_To_Row;
	else if ((this->Determinant() == 0))
		throw Matrix_Error::Determinant_Is_Zero;
	else
	{
		// Inverse(A) = adj(A) * 1/Det(A)
		Matrix InvMatrix = this->Adjoint();
		double DetTemp = 1 / this->Determinant();
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
Matrix Matrix::Solve(Matrix SM1)
{
	if (this->column() != SM1.row())
		throw Matrix_Error::Dimension_Error;
	else
	{
		// SM1 has no Adjoint Matrix, Inverse(SM1) doesn't exist
		if (this->row() != this->column())
			throw Matrix_Error::Can_Not_Solve;
		else
		{
			// Ax = B, Inv(A)Ax = Inv(A)B, x = Inv(A)B
			Matrix Inv = this->Inverse();
			Matrix Ans = Inv * SM1;
			return Ans;
		}
	}
}
// Least Square Solve Linear
Matrix Matrix::LeastSquare(Matrix Y)
{
	// (A.Trans() * A).Inverse * A.Trans() * Y = X
	Matrix A = *this;
	Matrix ATemp = A.Trans();
	A = ATemp * A;
	A = A.Inverse();
	A = A * ATemp;
	A = A * Y;
	return A;
}
// Find EigenValue and EigenVector
std::vector<Matrix> Matrix::Eigen()
{
	if (this->row() != this->column())
		throw Matrix_Error::Rank_Not_Equal_To_Row;
	else if (this->row() > 3)
		throw Matrix_Error::Matrix_Size_Out_of_Range;
	else
	{
		std::vector<Matrix>Eigen;
		double tolerant = 1E-10;
		// ET[0] = EigenValue ET[1] = EigenVector
		Matrix EigenTemp[2];
		std::vector<double>ValueTemp;
		std::vector<std::vector<double>>VectorTemp;
		if (this->row() == 1)
		{
			// A - λI = 0
			// EigenValue = λ = A, EigenVector = I = 1
			ValueTemp.push_back(this->Data[0][0]);
			std::vector<double>VecTemp;
			VecTemp.push_back(1);
			VectorTemp.push_back(VecTemp);
		}
		else if(this->row() == 2)
		{
			// aλ^2 + bλ + c = 0
			double a, b, c, x1, x2;
			a = 1;
			b = -(this->Data[0][0] + this->Data[1][1]);
			c = -(this->Data[1][0] * this->Data[0][1]) + (this->Data[0][0] * this->Data[1][1]);
			// x = [-b+-(b^2 - 4ac)^1/2]/2a
			x1 = (-b + sqrt((pow(b, 2) - 4 * a*c))) / 2;
			x2 = (-b - sqrt((pow(b, 2) - 4 * a*c))) / 2;
			ValueTemp.push_back(x1);
			if (x1 != x2)
				ValueTemp.push_back(x2);
			// EigenValue
			for (unsigned int i = 0; i < ValueTemp.size(); i++)
			{
				std::vector<double>RowTemp;
				for (unsigned int j = 0; j < 2; j++)
				{
					if (i == j)
						RowTemp.push_back(ValueTemp[i]);
					else
						RowTemp.push_back(0);
				}
				EigenTemp[0].Data.push_back(RowTemp);
			}
			// Get EigenVector
			for (unsigned int i = 0; i < ValueTemp.size(); i++)
			{
				Matrix Eg = *this;
				for (unsigned int j = 0; j < Eg.row(); j++)
					Eg.Data[j][j] -= ValueTemp[i];
				Eg = Eg.Gaussian(1E-8);
				// a00k1 = -a01k2, k1 = -a01, k2 = a00
				double k1, k2, NM;
				k1 = -Eg.Data[0][1];
				k2 = Eg.Data[0][0];
				// Normalization
				NM = pow((pow(k1, 2) + pow(k2, 2)), 0.5);
				k1 /= NM;
				k2 /= NM;
				// Vector is nonzero
				std::vector<double>Temp;
				if (!(k1 == 0 && k2 == 0))
				{
					Temp.push_back(k1);
					Temp.push_back(k2);
				}
				// EigenVectot = {1, 0}
				else if (k1 == 0 && k2 != 0)
				{
					Temp.push_back(1);
					Temp.push_back(0);
				}
				// EigenVector
				EigenTemp[1].Data.push_back(Temp);
			}
		}
		else if(this->row() == 3)
		{
			// aλ^3 + bλ^2 + cλ + d = 0
			double a, b, c, d, Q, R, x1, x2, x3, thta;
			a = 1;
			b = -(this->Data[0][0] + this->Data[1][1] + this->Data[2][2]);
			c = (this->Data[0][0] * this->Data[1][1] + this->Data[1][1] * this->Data[2][2] + this->Data[0][0] * this->Data[2][2]) - (this->Data[0][1] * this->Data[1][0] + this->Data[0][2] * this->Data[2][0] + this->Data[1][2] * this->Data[2][1]);
			d = -(this->Data[0][0] * this->Data[1][1] * this->Data[2][2] + this->Data[0][1] * this->Data[1][2] * this->Data[2][0] + this->Data[0][2] * this->Data[1][0] * this->Data[2][1]) + (this->Data[0][2] * this->Data[1][1] * this->Data[2][0] + this->Data[0][0] * this->Data[1][2] * this->Data[2][1] + this->Data[0][1] * this->Data[1][0] * this->Data[2][2]);
			Q = (pow(b, 2) - 3 * c) / 9;
			R = (2 * pow(b, 3) - 9 * b * c + 27 * d) / 54;
			thta = acos((R / sqrt(pow(Q, 3))));
			// x1, x2, x3 Compare with tolerant
			x1 = -2 * sqrt(Q) * cos(thta / 3) - b / 3;
			if (abs(x1) < tolerant)
				x1 = 0;
			x2 = -2 * sqrt(Q) * cos((thta + 2 * M_PI) / 3) - b / 3;
			if (abs(x2) < tolerant)
				x2 = 0;
			x3 = -2 * sqrt(Q) * cos((thta - 2 * M_PI) / 3) - b / 3;
			if (abs(x3) < tolerant)
				x3 = 0;
			// EigenValue
			ValueTemp.push_back(x1);
			if(x1 != x2)
				ValueTemp.push_back(x2);
			if (x1 != x3 && x2 != x3)
				ValueTemp.push_back(x3);
			for (unsigned int i = 0; i < ValueTemp.size(); i++)
			{
				std::vector<double>RowTemp;
				for (unsigned int j = 0; j < 3; j++)
				{
					if (i == j)
						RowTemp.push_back(ValueTemp[i]);
					else
						RowTemp.push_back(0);
				}
				EigenTemp[0].Data.push_back(RowTemp);
			}
			// Get EigenVector
			bool OneFlag = false;
			for (unsigned int i = 0; i < ValueTemp.size(); i++)
			{
				Matrix Eg = *this;
				std::vector<double>VecTemp;
				for (unsigned int j = 0; j < Eg.row(); j++)
					Eg.Data[j][j] -= ValueTemp[i];
				Eg = Eg.Gaussian(1E-8);
				double k1, k2, k3, NM, tolerant;
				tolerant = 1E-6;
				if (Eg.Data[0][0] != 0)
				{
					k2 = Eg.Data[1][2];
					k3 = -Eg.Data[1][1];
					k1 = -(Eg.Data[0][1] * Eg.Data[1][2] - Eg.Data[0][2] * Eg.Data[1][1]) / Eg.Data[0][0];
					// Normalization
					NM = sqrt((pow(k1, 2) + pow(k2, 2) + pow(k3, 2)));
					if (abs(k1 / NM) > tolerant)
						VecTemp.push_back(k1 / NM);
					else
						VecTemp.push_back(0);
					if (abs(k2 / NM) > tolerant)
						VecTemp.push_back(k2 / NM);
					else
						VecTemp.push_back(0);
					if (abs(k3 / NM) > tolerant)
						VecTemp.push_back(k3 / NM);
					else
						VecTemp.push_back(0);
				}
				else
				{
					if (OneFlag)
						continue;
					// k1 = any, k2 = 0, k3 = 0, After Normalization k1 = 1, k2 = 0, k3 = 0
					VecTemp.push_back(1);
					VecTemp.push_back(0);
					VecTemp.push_back(0);
					OneFlag = true;
				}
				EigenTemp[1].Data.push_back(VecTemp);
				VecTemp.clear();
			}
		}
		for (unsigned int i = 0; i < 2; i++)
			Eigen.push_back(EigenTemp[i]);
		return Eigen;
	}
}
// PowerMethod
std::vector<Matrix> Matrix::PM()
{
	if (this->row() != this->column())
		throw Matrix_Error::Row_And_Column_NotEqual;
	else
	{
		Matrix CurrentM = *this;
		Matrix EigenTemp[2];
		double tolerant = 1E-12;
		// EigenTemp[0] = EigenValue, EigenTemp[1] = EigenVector
		std::vector<double>ValueTemp;
		std::vector<Matrix>Eigen;
		while (CurrentM.row() > 0)
		{
			// initial
			std::vector<double>Origin;
			std::vector<double>Next;
			for (unsigned int i = 0; i < CurrentM.row(); i++)
			{
				Origin.push_back(1);
			}
			// EigenValue
			double EigenValue, scaling;
			scaling = 0;
			// Jump Out while power has run 2000 times
			int Jump = 2000;
			Next = Origin;
			while(1)
			{
				bool IsEigen = false;
				// AX(k) = X(k+1)
				for (unsigned int i = 0; i < CurrentM.row(); i++)
				{
					Next[i] = 0;
					for (unsigned int j = 0; j < CurrentM.row(); j++)
					{
						Next[i] += CurrentM.Data[i][j] * Origin[j];
					}
				}
				EigenValue = scaling;
				scaling = 0;
				// Scaling
				for (unsigned int i = 0; i < CurrentM.row(); i++)
				{
					if (abs(Next[i]) > abs(scaling))
					{
						scaling = Next[i];
					}
				}
				for (unsigned int i = 0; i < CurrentM.row(); i++)
				{
					Next[i] /= scaling;
				}
				// Jump out or in tolerant
				if ((abs(EigenValue - scaling) < tolerant))
				{
					IsEigen = true;
				}
				else if ((Jump - 1) == 0)
				{
					throw Matrix_Error::Not_Diagonal;
				}
				Jump--;
				if (IsEigen)
				{
					// EigenValue
					ValueTemp.push_back(EigenValue);
					break;
				}
				Origin = Next;
			}
			// Deflation
			Matrix Temp = CurrentM;
			CurrentM.Data.clear();
			for (unsigned int i = 1; i < Temp.row(); i++)
			{
				std::vector<double>NewRow;
				for (unsigned int j = 1; j < Temp.row(); j++)
				{
					NewRow.push_back(Temp.Data[i][j] - ( Origin[i]/ Origin[0]) * Temp.Data[0][j]);
				}
				CurrentM.Data.push_back(NewRow);
			}
		}
		// EigenVector
		for (unsigned int i = 0; i < ValueTemp.size(); i++)
		{
			// Solve Ax = 0
			Matrix CurrentEg = *this;
			// Answer
			std::vector<double>EgV(this->row());
			// Ax = b, b = 0
			std::vector<double>Zero(this->row());
			// Initial
			for (unsigned int j = 0; j < CurrentEg.row(); j++)
			{
				CurrentEg.Data[j][j] -= ValueTemp[i];
				Zero[j] = 0;
			}
			// Gaussian Tolerant
			CurrentEg = CurrentEg.Gaussian(1E-5);
			// Find nonPivot Column
			// Record Position
			std::vector<int>PR;
			for (int cur_row = 0, cur_col = 0; cur_row < CurrentEg.row() && cur_col < CurrentEg.row(); cur_row++, cur_col++)
			{
				if (CurrentEg.Data[cur_row][cur_col] == 0)
				{
					cur_row--;
					PR.push_back(cur_col);
				}
			}
			// initial ZeroVector
			for (unsigned int j = 0; j < PR.size(); j++)
			{
				EgV[PR[j]] = -1;
				for (unsigned int k = 0; k < CurrentEg.row(); k++)
				{
					Zero[k] += CurrentEg.Data[k][PR[j]];
					CurrentEg.Data[k][PR[j]] = 0;
				}
			}
			// Find EigenVector
			for (int cur_row = CurrentEg.row() - 1; cur_row >= 0; cur_row--)
			{
				for (int cur_col = CurrentEg.row() - 1; cur_col >= 0; cur_col--)
				{
					if (CurrentEg.Data[cur_row][cur_col] != 0)
					{
						EgV[cur_col] = Zero[cur_row] / CurrentEg.Data[cur_row][cur_col];
						// Clear all element from this column
						for (int j = cur_row - 1; j >= 0; j--)
						{
							Zero[j] -= CurrentEg.Data[j][cur_col] * EgV[cur_col];
							CurrentEg.Data[j][cur_col] = 0;
						}
						break;
					}
				}
			}
			// Get EigenVector
			// Normalization
			double NM = 0;
			for (unsigned int j = 0; j < EgV.size(); j++)
			{
				NM += EgV[j] * EgV[j];
			}
			NM = sqrt(NM);
			for (unsigned int j = 0; j < EgV.size(); j++)
			{
				EgV[j] /= NM;
			}
			EigenTemp[1].Data.push_back(EgV);
		}
		for (unsigned int i = 0; i < ValueTemp.size(); i++)
		{
			std::vector<double>RowTemp;
			for (unsigned int j = 0; j < this->row(); j++)
			{
				if (j == i)
					RowTemp.push_back(ValueTemp[i]);
				else
					RowTemp.push_back(0);
			}
			EigenTemp[0].Data.push_back(RowTemp);
		}
		for (unsigned int i = 0; i < 2; i++)
			Eigen.push_back(EigenTemp[i]);
		return Eigen;
	}
}
// Check if it is a zero matrix
bool Matrix::IsZeroM()
{
	for (unsigned int i = 0; i < this->row(); i++)
	{
		for (unsigned int j = 0; j < this->column(); j++)
		{
			if (this->Data[i][j])
				return false;
			else if (i == this->row() - 1 && j == this->column() - 1)
				return true;
		}
	}
}
