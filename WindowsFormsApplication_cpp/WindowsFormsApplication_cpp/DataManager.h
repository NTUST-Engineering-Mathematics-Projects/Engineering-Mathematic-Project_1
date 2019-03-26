#pragma once
#include<iostream>
#include<fstream>
#include "Vector.h"
#include "Matrix.h"

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
