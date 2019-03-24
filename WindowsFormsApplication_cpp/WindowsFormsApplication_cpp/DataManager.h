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
};

struct Matrix
{
	std::string Name;
	std::vector<std::vector<double>>Data;
	//�x�}����
	int row;
	int column;
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
