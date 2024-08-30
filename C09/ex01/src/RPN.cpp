#include "RPN.hpp"
#include <sstream>
#include "main.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

double	RPN::calculate(const std::string& input) const
{
	(void)input;
	return 0;
}

double RPN::stringToInt(const std::string& str) const
{
	double nbr;

	std::stringstream ss(str);
	ss >> nbr;
	return (nbr);
}

std::string RPN::intToString(double number) const
{
    std::stringstream ss;
    ss << number;
    return ss.str();
}

void	RPN::createStack(const std::string& input)
{
	std::istringstream iss(input);
	std::string token;

	while (iss >> token)
	{
		if (token == "+")
		{
			double op1 = stringToInt(_stack.top());
			_stack.pop();
			double op2 = stringToInt(_stack.top());
			_stack.pop();
			_stack.push(intToString(op1 + op2));
			// std::cout << "addition: " << op2 + op1  << std::endl;
		}
		else if (token == "-")
		{
			double op1 = stringToInt(_stack.top());
			_stack.pop();
			double op2 = stringToInt(_stack.top());
			_stack.pop();
			_stack.push(intToString(op2 - op1));
			// std::cout << "soustraction: " << op2 - op1 << std::endl;
		}
		else if (token == "*")
		{
			double op1 = stringToInt(_stack.top());
			_stack.pop();
			double op2 = stringToInt(_stack.top());
			_stack.pop();
			_stack.push(intToString(op2 * op1));
			// std::cout << "multiplicaiton: " << op2 * op1 << std::endl;
		}
		else if (token == "/")
		{
						double op1 = stringToInt(_stack.top());
			_stack.pop();
			double op2 = stringToInt(_stack.top());
			_stack.pop();
			_stack.push(intToString(op2 / op1));
			// std::cout << "division: " << op2 / op1 << std::endl;
		}
		else _stack.push(token);
	}
}

void RPN::displayStack()
{
	// std::cout << "Contenu de la pile :" << std::endl;
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
	double operandCount = 0;
	double nbrCount = 0;
	bool zeroFlag = false;

	while (iss >> token)
	{
		std::istringstream tokenStream(token);
		double number;
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