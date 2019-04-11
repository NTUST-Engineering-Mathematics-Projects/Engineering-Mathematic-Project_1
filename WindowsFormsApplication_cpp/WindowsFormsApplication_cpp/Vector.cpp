#include "Vector.h"
#define _USE_MATH_DEFINES
#include <math.h>

int Vector::dimension()
{
	return this->Data.size();
}
// Vector Constructors operation
Vector::Vector()
{}
Vector::Vector(double d)
{
	Data.push_back(d);
}
Vector::Vector(int i)
{
	Data.push_back((double)i);
}
Vector::Vector(std::string name)
{
	Name = name;
}
Vector::Vector(std::string name, std::vector<double> data)
{
	Name = name;
	Data = data;
}
// Vector OperatorOverLoading
Vector Vector::operator+(Vector & v)
{
	if (this->dimension() != v.dimension())
		throw Vector_Error::Dimension_Not_Equal;
	if (this->IsZeroVector())
	{
		Vector ans = v;
		return ans;
	}
	if (v.IsZeroVector())
	{
		Vector ans = *this;
		return ans;
	}
	Vector result;
	result.Data.clear();
	for (unsigned int i = 0; i < this->Data.size(); i++)
	{
		result.Data.push_back(this->Data[i] + v.Data[i]);
	}
	return result;
}
Vector Vector::operator-(Vector& v)
{
	if (this->dimension() != v.dimension())
		throw Vector_Error::Dimension_Not_Equal;
	if (v.IsZeroVector())
	{
		Vector ans = *this;
		return ans;
	}
	Vector result;
	result.Data.clear();
	for (unsigned int i = 0; i < this->Data.size(); i++)
	{
		result.Data.push_back(this->Data[i] - v.Data[i]);
	}
	return result;
}
// Dot of Vector
Vector Vector::operator*(Vector & v)
{
	Vector result;
	// Multiplication of Vector(Scalar)
	// If size == 1, is scalar.
	if (this->Data.size() == 1)
	{
		for (unsigned int i = 0; i < v.Data.size(); i++)
		{
			double temp = v.Data[i] * this->Data[0];
			result.Data.push_back(temp);
		}
	}
	else if (v.Data.size() == 1)
	{
		for (unsigned int i = 0; i < this->Data.size(); i++)
		{
			double temp = this->Data[i] * v.Data[0];
			result.Data.push_back(temp);
		}
	}
	// Dot of Vector
	else
	{
		if (this->dimension() != v.dimension())
			throw Vector_Error::Dimension_Not_Equal;
		if (this->IsZeroVector() || v.IsZeroVector())
		{
			return Vector(0);
		}
		double dot = 0;
		for (unsigned int i = 0; i < v.Data.size(); i++)
		{
			dot += (v.Data[i] * this->Data[i]);
		}
		result.Data.push_back(dot);
	}
	return result;
}
// Norm of Vector
const double Vector::norm()
{
	double Norm = 0;
	for (unsigned int i = 0; i < this->Data.size(); i++)
	{
		Norm += pow(this->Data[i], 2.0);
	}
	Norm = pow(Norm, 0.5);
	return Norm;
}
// Normalization of Vector
Vector Vector::normalization()
{
	Vector result;
	result.Data.clear();
	if (this->IsZeroVector())
	{
		for (unsigned int i = 0; i < this->Data.size(); i++)
			result.Data.push_back(0);
		return result;
	}
	double N = 0;
	for (unsigned int i = 0; i < this->Data.size(); i++)
	{
		N += pow(this->Data[i], 2);
	}
	N = sqrt(N);
	for (unsigned int i = 0; i < this->Data.size(); i++)
	{
		result.Data.push_back((this->Data[i] / N));
	}
	return result;
}
// Orthogonal judgement
const bool Vector::Orthogonal(Vector & v)
{
	// Dot of two vectors is 0
	// Zero vector is orthogonal to every vector
	if (this->IsZeroVector() || v.IsZeroVector())
		return true;
	Vector temp = *this * v;
	return (temp.Data[0] == 0) ? true : false;
}
// Judge if it is a zervector
const bool Vector::IsZeroVector()
{
	for (unsigned int i = 0; i < this->Data.size(); i++)
	{
		if (this->Data[i])
			return false;
	}
	return true;
}
// Cross product operating, The plane normal that is produced by two vectors
Vector Vector::crossProduct(Vector& v)
{
	if (this->dimension() != 3 || v.dimension() != 3)
		throw Vector_Error::Dimension_Not_Equal;
	Vector answer;
	double i, j, k;
	i = this->Data[1] * v.Data[2] - this->Data[2] * v.Data[1];
	answer.Data.push_back(i);
	j = -(this->Data[0] * v.Data[2] - this->Data[2] * v.Data[0]);
	answer.Data.push_back(j);
	k = this->Data[0] * v.Data[1] - this->Data[1] * v.Data[0];
	answer.Data.push_back(k);
	return answer;
}
//Component of a on b
const double Vector::component(Vector& v)
{
	return (*this * v).Data[0] / v.norm();
}
//Projection of a on b
Vector Vector::projection(Vector& v)
{
	double d1, d2;
	d1 = (*this * v).Data[0];
	d2 = (v * v).Data[0];
	Vector tv = Vector(d1 / d2);
	return (tv * v);
}
//The angle between two vectors
const double Vector::angle(Vector& v)
{
	double theta = (*this * v).Data[0] / this->norm() / v.norm();
	double result = acos(theta) * 180 / M_PI;
	return result;
}
//Triangle area
const double Vector::triangle(Vector& v)
{
	// It works with more than 3-dimension vector
	return (this->norm() * v.norm() * sin(this->angle(v) * M_PI / 180)) * 0.5;
}
//Parallel judgement
const bool Vector::parallel(Vector& v)
{
	if (this->dimension() != v.dimension())
		throw Vector_Error::Dimension_Not_Equal;
	if ((this->IsZeroVector() && !v.IsZeroVector()) || (!this->IsZeroVector() && v.IsZeroVector()))
		return false;
	double Magnification = 0;
	for (unsigned int i = 0; i < this->Data.size(); i++)
	{
		if (!Magnification)
			Magnification = this->Data[i] / v.Data[i];
		if (Magnification != (this->Data[i] / v.Data[i]) && (!Magnification))
			return false;
	}
	return true;
}
// Plane Normal
Vector Vector::PlaneNormal(Vector & v)
{
	return this->crossProduct(v);
}
// Linear independent judgement
const bool IsLinearIndependent(std::vector<Vector> v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (i != v.size() - 1)
		{
			if (v[i].dimension() != v[i + 1].dimension())
			{
				throw Vector_Error::Dimension_Not_Equal;
			}
		}
	}
	if (v.size() < v[0].dimension())
		return false;
	std::vector<std::vector<double>> Matrix;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		std::vector<double>temp;
		for (unsigned int j = 0; j < v.size(); j++)
		{
			temp.push_back(v[j].Data[i]);
		}
		Matrix.push_back(temp);
	}
	// Using Gaussian
	for (unsigned int cur_row, cur_col = 0; cur_row < Matrix.size() && cur_col < Matrix[0].size(); cur_row++, cur_col++)
	{
		// Find CurrentMax
		double CMax = abs(Matrix[cur_row][cur_col]);
		int MRow = cur_row;
		for (int i = cur_row + 1; i < Matrix.size(); i++)
		{
			if (abs(Matrix[i][cur_col]) > CMax)
			{
				CMax = abs(Matrix[i][cur_col]);
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
			//ExChange Row
			std::vector<double>buf = Matrix[cur_row];
			Matrix[cur_row] = Matrix[MRow];
			Matrix[MRow] = buf;
		}
		// Clear all nonzero columns
		for (int i = cur_row + 1; i < Matrix.size(); i++)
		{
			if (Matrix[i][cur_col] == 0)
			{
				continue;
			}
			for (int j = cur_col + 1; j < Matrix[i].size(); j++)
			{
				Matrix[i][j] -= (Matrix[i][cur_col] / Matrix[cur_row][cur_col] * Matrix[cur_row][j]);
			}
			Matrix[i][cur_col] = 0;
		}
	}
	// Compare with tolerant
	for (unsigned int i = 0; i < Matrix.size(); i++)
	{
		for (unsigned int j = 0; j < Matrix[i].size(); j++)
		{
			if (abs(Matrix[i][j]) < 1E-6)
				Matrix[i][j] = 0;
		}
	}
	double Det = 1;
	for (unsigned int i = 0; i < Matrix.size(); i++)
	{
		Det *= Matrix[i][i];
	}
	if (Det)
		return true;
	else
		return false;
}
// Vector OrthogonalBasis
std::vector<Vector> OrthogonalBasis(std::vector<Vector> v)
{
	std::vector<Vector>result;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		Vector basis;
		if (i == 0)
		{
			basis = v[i];
			result.push_back(basis);
		}
		else
		{
			basis = v[i];
			for (int j = result.size() - 1; j >= 0; j--)
			{
				basis = basis - v[i].projection(result[j]);
			}
			result.push_back(basis);
		}
	}
	// Normalization
	for (unsigned int i = 0; i < result.size(); i++)
	{
		double nor = result[i].norm();
		for (unsigned int j = 0; j < result[i].Data.size(); j++)
		{
			result[i].Data[j] /= nor;
		}
	}
	return result;
}