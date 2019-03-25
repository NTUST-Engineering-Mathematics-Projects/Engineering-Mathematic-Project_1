#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
//�w�q�V�q��Ƶ��c
struct Vector
{
	std::string Name;
	std::vector<double> Data;
	//�V�q����
	int dimension;
	//Constructors
	Vector::Vector();
	Vector::Vector(double d);
	Vector::Vector(int i);
	//OperatorOverLoading
	const Vector& operator+(const Vector& v);
	const Vector& operator-(const Vector& v);
	// Multiplication of Vector
	friend const Vector& operator*(const Vector& v, const Vector& v2);
	// Dot of Vector
	const double operator*(const Vector& v);
	// Norm of Vector
	const double norm();
	// Normalization of Vector
	const Vector& normalization();
	// Orthogonal judgement
	const bool Orthogonal(const Vector& v);
};

struct Matrix
{
	std::string Name;
	std::vector<std::vector<double>>Data;
	//�x�}����
	int row;
	int column;
	// Constructors
	Matrix();
	Matrix(double d);
	Matrix(int i);
};

//�w�q���޸��class
class DataManager
{
private:
	//�x�s�V�q���
	std::vector<Vector> Vectors;
	std::vector<Matrix> Matrixs;
	//�����V�qID�A�Ω󱱺�
	int  VectorVariableIndex;
	int MatrixVariableIndex;
	//�����ɮ׸��|�W��
	std::string FileName;
public:
	DataManager();
	//Ū���ɮצW��(�Y�O'V'�h�V�q, 'M'�h�x�})
	bool ReadFileName();
	//Ū���V�q���
	bool LoadVectorData();
	//Ū���x�}���
	bool LoadMatrixData();
	//���o�Ҧ��V�q���
	std::vector<Vector> GetVectors();
	//���o�Ҧ��x�}���
	std::vector<Matrix> GetMatrixs();
	//�]�m�ɮ׸��|�W��
	void SetFileName(std::string fileName);
	//Vector or Matrix
	int VM;
};
