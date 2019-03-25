#include"DataManager.h"

std::fstream fin;

bool DataManager::ReadFileName()
{
	//�}���ɮסA�ǤJopen��ƪ��ѼƦ���ӡA���}�_���ɮצW�١A�}���ɮת��Ҧ��Ѽ�(�o��std::ios::in��Ū��(��J)���A)
	fin.open(FileName, std::ios::in);
	//Ū�����Ѧ^��false
	if (!fin)
	{
		return false;
	}
	else
	{
		std::string RealFileName;
		for (unsigned int i = 0; i < FileName.length(); i++)
		{
			if (FileName[i] == '.')
			{
				for (unsigned int j = i - 1; j > 0; j--)
				{
					if (FileName[j] != '\\')
					{
						RealFileName.insert(RealFileName.begin(), FileName[j]);
					}
					else
						break;
				}
				break;
			}
		}
		if (RealFileName[0] == 'V')
		{
			VM = 0;
			return this->LoadVectorData();
		}
		else
		{
			VM = 1;
			return this->LoadMatrixData();
		}
	}
}

DataManager::DataManager()
{
	VectorVariableIndex = 0;
	MatrixVariableIndex = 0;
}

bool DataManager::LoadVectorData()
{
	//�аO��eŪ���V�qID
	int currentLoadVectorID = 0;
	//Dimension
	int dimension;
	//�w�q�V�q��ƼȦs�ܼ�
	std::vector<double> tempVectorData;
	//�w�qŪ���ɮצr��Ȧs�ܼ�
	std::string tempSring;
	//�q�ɮ�Ū���r��A�ѪR���V�q�`��
	fin >> tempSring;
		
	//����Ū�ɰj��A�æbŪ���ɮ׵����ɵ���
	while (!fin.eof())
	{
		//�q�ɮ�Ū���r��
		fin >> tempSring;
		//�ѪR��V�q�аO"V"
		if (tempSring == "V")
		{
			if (currentLoadVectorID != 0)
			{
				//�w�q�Ȧs�V�q��Ƶ��c
				Vector tempVector;
				//�s�J�V�q���
				tempVector.Data = tempVectorData;
				//�w�q�V�q�ܼƦW�١A��VectorVariableIndex�ܼƧ@�W�٪�����
				std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
				//�s�J�V�q�ܼƦW��
				tempVector.Name = vectorVariableTemp;
				//�s�J�V�q
				Vectors.push_back(tempVector);
				//���WVectorVariableIndex�A�H�T�O�ܼƦW�٤�����
				VectorVariableIndex++;
				//�M���V�q��ƼȦs
				tempVectorData.clear();
			}
			//���WcurrentLoadVectorID�A�аO���eŪ���V�qID
			currentLoadVectorID++;
			//�q�ɮ�Ū���r��A�ѪR���V�q����
			fin >> tempSring;
			dimension = (int)strtod(tempSring.c_str(), NULL);
		}
		else
		{
			//Ū���V�q��ơA�ñNstring�ରdouble
			double value;
			value = (double)strtod(tempSring.c_str(), NULL);
			//�N�V�q��Ʀs�J�Ȧs
			tempVectorData.push_back(value);
		}
			
	}
	//Ū�J��J�ɮפ��̫�@�ӦV�q��T
	Vector tempVector;
	tempVector.dimension = dimension;
	tempVector.Data = tempVectorData;
	std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
	tempVector.Name = vectorVariableTemp;
	Vectors.push_back(tempVector);
	VectorVariableIndex++;
	//Ū�����\�^��false
	fin.close();
	return true;
}

bool DataManager::LoadMatrixData()
{
	//�аO��eŪ���x�}ID
	int currentLoadMatrixID = 0;
	//Dimension
	int Row, Column;
	//�x�}����Buffer
	std::vector<double>bufferVector;
	int currentRow = 0;
	//�w�q�x�}��ƼȦs�ܼ�
	std::vector<std::vector<double>> tempMatrixData;
	//�w�qŪ���ɮצr��Ȧs�ܼ�
	std::string tempSring;
	//�q�ɮ�Ū���r��A�ѪR���x�}�`��
	fin >> tempSring;

	//����Ū�ɰj��A�æbŪ���ɮ׵����ɵ���
	while (!fin.eof())
	{
		//�q�ɮ�Ū���r��
		fin >> tempSring;
		//�ѪR��x�}�аO"M"
		if (tempSring == "M")
		{
			if (currentLoadMatrixID != 0)
			{
				//�w�q�Ȧs�x�}��Ƶ��c
				Matrix tempMatrix;
				//�s�J�x�}���
				tempMatrixData.push_back(bufferVector);
				tempMatrix.Data = tempMatrixData;
				//�w�q�x�}�ܼƦW�١A��matrixVariableIndex�ܼƧ@�W�٪�����
				std::string matrixVariableTemp = "$m" + std::to_string(MatrixVariableIndex);
				//�s�J�x�}�ܼƦW��
				tempMatrix.Name = matrixVariableTemp;
				//�s�J�x�}
				Matrixs.push_back(tempMatrix);
				//���WmatrixVariableIndex�A�H�T�O�ܼƦW�٤�����
				MatrixVariableIndex++;
				//�M���x�}��ƼȦs
				tempMatrixData.clear();
				bufferVector.clear();
				currentRow = 0;
			}
			//���WcurrentLoadMatrixID�A�аO���eŪ���x�}ID
			currentLoadMatrixID++;
			//�q�ɮ�Ū���r��A�ѪR���x�}����
			// Row
			fin >> tempSring;
			 Row = (int)strtod(tempSring.c_str(), NULL);
			//Column
			fin >> tempSring;
			Column = (int)strtod(tempSring.c_str(), NULL);

		}
		else
		{
			//Ū���x�}��ơA�ñNstring�ରdouble
			double value;
			value = (double)strtod(tempSring.c_str(), NULL);
			//�N�x�}��Ʀs�J�Ȧs
			if (currentRow == Row)
			{
				tempMatrixData.push_back(bufferVector);
				bufferVector.clear();
				bufferVector.push_back(value);
				currentRow = 1;
			}
			else
			{
				bufferVector.push_back(value);
				currentRow++;
			}
		}

	}
	//Ū�J��J�ɮפ��̫�@�ӯx�}��T
	Matrix tempMatrix;
	tempMatrixData.push_back(bufferVector);
	tempMatrix.Data = tempMatrixData;
	std::string matrixVariableTemp = "$m" + std::to_string(MatrixVariableIndex);
	tempMatrix.Name = matrixVariableTemp;
	Matrixs.push_back(tempMatrix);
	MatrixVariableIndex++;
	//Ū�����\�^��false
	fin.close();
	return true;
}

std::vector<Vector> DataManager::GetVectors()
{
	return Vectors;
}
std::vector<Matrix> DataManager::GetMatrixs()
{
	return Matrixs;
}
void DataManager::SetFileName(std::string fileName)
{
	FileName = fileName;
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
// Vector OperatorOverLoading
const Vector & Vector::operator+(const Vector & v)
{
	for (unsigned int i = 0; i < this->Data.size(); i++)
	{
		this->Data[i] += v.Data[i];
	}
	return *this;
}
const Vector& Vector::operator-(const Vector& v)
{
	for (unsigned int i = 0; i < this->Data.size(); i++)
	{
		this->Data[i] -= v.Data[i];
	}
	return *this;
}
// Multiplication of Vector
// Vector friend function
const Vector& operator*(const Vector& v, const Vector& v2)
{
	Vector scal;
	double value;
	if (v.Data.size() < v2.Data.size())
	{
		for (unsigned int i = 0; i < v2.Data.size(); i++)
		{
			value = 0.0;
			value = v2.Data[i] * v.Data[0];
			scal.Data.push_back(value);
		}
	}
	else
	{
		for (unsigned int i = 0; i < v.Data.size(); i++)
		{
			value = 0.0;
			value = v.Data[i] * v2.Data[0];
			scal.Data.push_back(value);
		}
	}
	return scal;
}
// Dot of Vector
const double Vector::operator*(const Vector & v)
{
	double dot;
	for (unsigned int i = 0; i < v.Data.size(); i++)
	{
		dot += (v.Data[i] * this->Data[i]);
	}
	return dot;
}
// Norm of Vector
const double Vector::norm()
{
	double Norm;
	for (unsigned int i = 0; i < this->Data.size(); i++)
	{
		Norm += pow(this->Data[i], 2.0);
	}
	Norm = pow(Norm, 0.5);
	return Norm;
}
// Normalization of Vector
const Vector & Vector::normalization()
{
	double N = this->norm();
	for (unsigned int i = 0; i < this->Data.size(); i++)
		this->Data[i] /= N;
	return *this;
}
// Orthogonal judgement
const bool Vector::Orthogonal(const Vector & v)
{	
	return ((*this * v) == 0.0) ? true : false;
}

// Matrix Constructors operation
Matrix::Matrix()
{}
Matrix::Matrix(double d)
{
	std::vector<double>temp;
	temp.push_back(d);
	this->Data.push_back(temp);
}
Matrix::Matrix(int i)
{
	std::vector<double>temp;
	temp.push_back((double)i);
	this->Data.push_back(temp);
}