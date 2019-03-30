#include "InfixToPostfix.h"

void InfToPos(std::vector<std::string> &Userinput)
{
	// Current String
	std::string currentS;
	std::vector<std::string>Stack;
	std::vector<std::string>OutputString;
	// * > +, -
	for (unsigned int i = 0; i < Userinput.size(); i++)
	{
		if (Userinput[i] == "(")
		{
			Stack.push_back(Userinput[i]);
		}
		else if (Userinput[i] == "-" || Userinput[i] == "+" || Userinput[i] == "*")
		{
			// If Stack is empty
			if (Stack.size() == 0)
			{
				Stack.push_back(Userinput[i]);
			}
			// Stack not empty, Judge the priority in Stack
			else
			{
				if(Userinput[i] == "+" || Userinput[i] == "-")
				{
					// ���F"("���Stack��pop_out
					while(!(Stack.size() == 0 || Stack[Stack.size() - 1] == "("))
					{
						OutputString.push_back(Stack[Stack.size() - 1]);
						Stack.pop_back();
					}
				}
				if (Userinput[i] == "*")
				{
					// �O"*"�Npop_out
					while (Stack[Stack.size() - 1] == "*")
					{
						OutputString.push_back(Stack[Stack.size() - 1]);
						Stack.pop_back();
						// Stack �ŭn���X
						if (Stack.size() == 0)
							break;
					}
				}
				Stack.push_back(Userinput[i]);
			}
		}
		else if (Userinput[i] == ")")
		{
			int flag = Stack.size() - 1;
			// �N"("�H�e���F��h�XStack
			while (Stack[flag] != "(")
			{
				OutputString.push_back(Stack[flag]);
				Stack.pop_back();
				// Stack �ŭn���X
				if (Stack.size() == 0)
					break;
				flag = Stack.size() - 1;
			}
			// �N"("�h�XStack
			Stack.pop_back();
		}
		// �¤�r�����s�JOutputString
		else
		{
			OutputString.push_back(Userinput[i]);
		}
		// �NStack�ѤU���ȷh�hOutputString
		if (i == Userinput.size() - 1)
		{
			for (int j = Stack.size() - 1; j >= 0; j--)
			{
				if (Stack[j] != "(")
				{
					OutputString.push_back(Stack[j]);
				}
			}
		}
	}
	// �ƻs��ƨ�Userinput
	Userinput.clear();
	for (unsigned int i = 0; i < OutputString.size(); i++)
		Userinput.push_back(OutputString[i]);
	return;
}