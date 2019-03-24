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
};

struct Matrix
{
	std::string Name;
	std::vector<std::vector<double>>Data;
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
	int MatrixVaribaleIndex;
	//紀錄檔案路徑名稱
	std::string FileName;
public:
	DataManager();
	//讀取向量資料
	bool ReadFileName();
	bool LoadVectorData();
	//讀取矩陣資料
	bool LoadMatrixData();
	//取得所有向量資料
	std::vector<Vector> GetVectors();
	//取得所有矩陣資料
	std::vector<Matrix> GetMatrixs();
	//設置檔案路徑名稱
	void SetFileName(std::string fileName);
};
