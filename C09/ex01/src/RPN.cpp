#include "RPN.hpp"
#include <sstream>
#include "main.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

void	RPN::calculate(const std::string& input)
{
	if (!checkInput(input))
	{
		(std::cout << "invalid input." << std::endl);
		return;
	}
	createStack(input);
	displayStack();
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

void RPN::applyOperation(OperationFunc op)
{
	double op1 = stringToInt(_stack.top());
	_stack.pop();
	double op2 = stringToInt(_stack.top());
	_stack.pop();
	_stack.push(intToString(op(op2, op1)));
}

void	RPN::createStack(const std::string& input)
{
	std::istringstream iss(input);
	std::string token;

	while (iss >> token)
	{
		if (token == "+")
			applyOperation(add);
		else if (token == "-")
			applyOperation(subtract);
		else if (token == "*")
			applyOperation(multiply);
		else if (token == "/")
			applyOperation(divide);
		else _stack.push(token);
	}
}

void RPN::displayStack()
{
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
				return (std::cout << "Number greater than 10: " << std::flush, false);
			if (number == 0)
				zeroFlag = true;
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (operandCount < 2)
				return (std::cout << "Less than two operands: " << std::flush, false);
			operandCount--;
			if (zeroFlag && token == "/")
				return (std::cout << "Divide by zero: " << std::flush, false);
			zeroFlag = false;
		}
		else
			return(false);
	}
	return (operandCount == 1 && nbrCount <= 10);
}

double RPN::add(double a, double b) { return a + b; }
double RPN::subtract(double a, double b) { return a - b; }
double RPN::multiply(double a, double b) { return a * b; }
double RPN::divide(double a, double b) { return a / b; }



