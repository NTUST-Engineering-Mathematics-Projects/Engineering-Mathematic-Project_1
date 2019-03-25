#include"DataManager.h"

std::fstream fin;

bool DataManager::ReadFileName()
{
	//開啟檔案，傳入open函數的參數有兩個，欲開起的檔案名稱，開啟檔案的模式參數(這邊std::ios::in為讀取(輸入)狀態)
	fin.open(FileName, std::ios::in);
	//讀取失敗回傳false
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
	//標記當前讀取向量ID
	int currentLoadVectorID = 0;
	//Dimension
	int dimension;
	//定義向量資料暫存變數
	std::vector<double> tempVectorData;
	//定義讀取檔案字串暫存變數
	std::string tempSring;
	//從檔案讀取字串，解析掉向量總數
	fin >> tempSring;
		
	//執行讀檔迴圈，並在讀到檔案結尾時結束
	while (!fin.eof())
	{
		//從檔案讀取字串
		fin >> tempSring;
		//解析到向量標記"V"
		if (tempSring == "V")
		{
			if (currentLoadVectorID != 0)
			{
				//定義暫存向量資料結構
				Vector tempVector;
				//存入向量資料
				tempVector.Data = tempVectorData;
				//定義向量變數名稱，依VectorVariableIndex變數作名稱的控管
				std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
				//存入向量變數名稱
				tempVector.Name = vectorVariableTemp;
				//存入向量
				Vectors.push_back(tempVector);
				//遞增VectorVariableIndex，以確保變數名稱不重複
				VectorVariableIndex++;
				//清除向量資料暫存
				tempVectorData.clear();
			}
			//遞增currentLoadVectorID，標記到當前讀取向量ID
			currentLoadVectorID++;
			//從檔案讀取字串，解析掉向量維度
			fin >> tempSring;
			dimension = (int)strtod(tempSring.c_str(), NULL);
		}
		else
		{
			//讀取向量資料，並將string轉為double
			double value;
			value = (double)strtod(tempSring.c_str(), NULL);
			//將向量資料存入暫存
			tempVectorData.push_back(value);
		}
			
	}
	//讀入輸入檔案中最後一個向量資訊
	Vector tempVector;
	tempVector.dimension = dimension;
	tempVector.Data = tempVectorData;
	std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
	tempVector.Name = vectorVariableTemp;
	Vectors.push_back(tempVector);
	VectorVariableIndex++;
	//讀取成功回傳false
	fin.close();
	return true;
}

bool DataManager::LoadMatrixData()
{
	//標記當前讀取矩陣ID
	int currentLoadMatrixID = 0;
	//Dimension
	int Row, Column;
	//矩陣換行Buffer
	std::vector<double>bufferVector;
	int currentRow = 0;
	//定義矩陣資料暫存變數
	std::vector<std::vector<double>> tempMatrixData;
	//定義讀取檔案字串暫存變數
	std::string tempSring;
	//從檔案讀取字串，解析掉矩陣總數
	fin >> tempSring;

	//執行讀檔迴圈，並在讀到檔案結尾時結束
	while (!fin.eof())
	{
		//從檔案讀取字串
		fin >> tempSring;
		//解析到矩陣標記"M"
		if (tempSring == "M")
		{
			if (currentLoadMatrixID != 0)
			{
				//定義暫存矩陣資料結構
				Matrix tempMatrix;
				//存入矩陣資料
				tempMatrixData.push_back(bufferVector);
				tempMatrix.Data = tempMatrixData;
				//定義矩陣變數名稱，依matrixVariableIndex變數作名稱的控管
				std::string matrixVariableTemp = "$m" + std::to_string(MatrixVariableIndex);
				//存入矩陣變數名稱
				tempMatrix.Name = matrixVariableTemp;
				//存入矩陣
				Matrixs.push_back(tempMatrix);
				//遞增matrixVariableIndex，以確保變數名稱不重複
				MatrixVariableIndex++;
				//清除矩陣資料暫存
				tempMatrixData.clear();
				bufferVector.clear();
				currentRow = 0;
			}
			//遞增currentLoadMatrixID，標記到當前讀取矩陣ID
			currentLoadMatrixID++;
			//從檔案讀取字串，解析掉矩陣維度
			// Row
			fin >> tempSring;
			 Row = (int)strtod(tempSring.c_str(), NULL);
			//Column
			fin >> tempSring;
			Column = (int)strtod(tempSring.c_str(), NULL);

		}
		else
		{
			//讀取矩陣資料，並將string轉為double
			double value;
			value = (double)strtod(tempSring.c_str(), NULL);
			//將矩陣資料存入暫存
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
	//讀入輸入檔案中最後一個矩陣資訊
	Matrix tempMatrix;
	tempMatrixData.push_back(bufferVector);
	tempMatrix.Data = tempMatrixData;
	std::string matrixVariableTemp = "$m" + std::to_string(MatrixVariableIndex);
	tempMatrix.Name = matrixVariableTemp;
	Matrixs.push_back(tempMatrix);
	MatrixVariableIndex++;
	//讀取成功回傳false
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