#pragma once
#include<iostream>
#include<fstream>
#include "Vector.h"
#include "Matrix.h"

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
