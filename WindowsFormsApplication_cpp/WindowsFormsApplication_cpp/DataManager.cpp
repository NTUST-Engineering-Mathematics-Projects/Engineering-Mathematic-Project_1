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
	// Clear Vector
	Vectors.clear();
	VectorVariableIndex = 0;
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
				tempVector.dimension = dimension;
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
	// Clear Matrixs
	Matrixs.clear();
	MatrixVariableIndex = 0;
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
	// �����Ƴ̫�@�榳�ťթ�Enter
	bool EnterFlag = true;

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
			if (currentRow == Column)
			{
				tempMatrixData.push_back(bufferVector);
				// �w�gŪ���̫�@�������ťթδ���
				if ( tempMatrixData.size() == Row && bufferVector.size() == Column)
				{
					EnterFlag = false;
					break;
				}
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
	// �׶}����P�_
	if(EnterFlag)
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