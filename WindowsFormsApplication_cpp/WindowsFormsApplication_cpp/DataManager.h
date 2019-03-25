#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
//定義向量資料結構
struct Vector
{
	std::string Name;
	std::vector<double> Data;
	//向量維度
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
	//矩陣維度
	int row;
	int column;
	// Constructors
	Matrix();
	Matrix(double d);
	Matrix(int i);
};

//定義控管資料class
class DataManager
{
private:
	//儲存向量資料
	std::vector<Vector> Vectors;
	std::vector<Matrix> Matrixs;
	//紀錄向量ID，用於控管
	int  VectorVariableIndex;
	int MatrixVariableIndex;
	//紀錄檔案路徑名稱
	std::string FileName;
public:
	DataManager();
	//讀取檔案名稱(若是'V'則向量, 'M'則矩陣)
	bool ReadFileName();
	//讀取向量資料
	bool LoadVectorData();
	//讀取矩陣資料
	bool LoadMatrixData();
	//取得所有向量資料
	std::vector<Vector> GetVectors();
	//取得所有矩陣資料
	std::vector<Matrix> GetMatrixs();
	//設置檔案路徑名稱
	void SetFileName(std::string fileName);
	//Vector or Matrix
	int VM;
};
