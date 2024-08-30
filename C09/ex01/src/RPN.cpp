#include "RPN.hpp"
#include <sstream>

RPN::RPN()
{
}

RPN::~RPN()
{
}

int	RPN::calculate(const std::string& input) const
{
	(void)input;
	return 0;
}

void	RPN::createStack(const std::string& input)
{
	std::istringstream iss(input);
	std::string token;

	while (iss >> token)
	{
		_stack.push(token);
	}
}

void RPN::displayStack()
{
	std::cout << "Contenu de la pile :" << std::endl;
	while (!_stack.empty())
	{
		std::cout << _stack.top() << ' ';
		_stack.pop();
	}
	std::cout << std::endl;
}

bool RPN::checkInput(const std::string& input) const
{
	std::istringstream iss(input);
	std::string token;
	int operandCount = 0;
	int nbrCount = 0;
	bool zeroFlag = false;

	while (iss >> token)
	{
		std::istringstream tokenStream(token);
		int number;
		if (tokenStream >> number)
		{
			operandCount++;
			nbrCount++;
			if (number > 9 || number < 0)
				return false;
			if (number == 0)
				zeroFlag = true;
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (operandCount < 2)
				return(false);
			operandCount--;
			if (zeroFlag && token == "/")
				return false;
			zeroFlag = false;
		}
		else
			return(false);
	}
	return (operandCount == 1 && nbrCount <= 10);
}