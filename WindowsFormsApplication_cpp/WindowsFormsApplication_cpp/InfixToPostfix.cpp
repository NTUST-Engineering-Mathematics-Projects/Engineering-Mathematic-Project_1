#include "InfixToPostfix.h"

void InfToPos(std::vector<std::string> &Userinput)
{
	// Current String
	std::string currentS;
	std::vector<std::string>Stack;
	std::vector<std::string>OutputString;
	//  >  > 
	for (unsigned int i = 0; i < Userinput.size(); i++)
	{
		if (Userinput[i] == "(")
		{

		}
		else if (Userinput[i] == ")")
		{

		}
		else if (Userinput[i] == "+" || Userinput[i] == "-")
		{

		}
		else if (Userinput[i] == "*")
		{

		}
		else if (Userinput[i] == "dot")
		{

		}
	}
}