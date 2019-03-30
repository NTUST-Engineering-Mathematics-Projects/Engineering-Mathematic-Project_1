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
					// 除了"("跟空Stack都pop_out
					while(!(Stack.size() == 0 || Stack[Stack.size() - 1] == "("))
					{
						OutputString.push_back(Stack[Stack.size() - 1]);
						Stack.pop_back();
					}
				}
				if (Userinput[i] == "*")
				{
					// 是"*"就pop_out
					while (Stack[Stack.size() - 1] == "*")
					{
						OutputString.push_back(Stack[Stack.size() - 1]);
						Stack.pop_back();
						// Stack 空要跳出
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
			// 將"("以前的東西搬出Stack
			while (Stack[flag] != "(")
			{
				OutputString.push_back(Stack[flag]);
				Stack.pop_back();
				// Stack 空要跳出
				if (Stack.size() == 0)
					break;
				flag = Stack.size() - 1;
			}
			// 將"("搬出Stack
			Stack.pop_back();
		}
		// 純文字直接存入OutputString
		else
		{
			OutputString.push_back(Userinput[i]);
		}
		// 將Stack剩下的值搬去OutputString
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
	// 複製資料到Userinput
	Userinput.clear();
	for (unsigned int i = 0; i < OutputString.size(); i++)
		Userinput.push_back(OutputString[i]);
	return;
}