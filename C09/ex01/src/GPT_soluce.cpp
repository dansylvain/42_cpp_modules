#include <iostream>
#include <stack>
#include <list>
#include <cstdlib>
#include <cstring>
#include <string> 

int main(int argc, char* argv[])
{
	if (argc != 2)
		return (std::cerr << "Usage: " << argv[0] << " <expression>\n", 1);

	std::stack<int, std::list<int> > s;
	char* input = argv[1];
	char* token = std::strtok(input, " ");

	while (token != NULL)
	{
		if (std::isdigit(token[0]))
			s.push(std::atoi(token));
		else
		{
			if (s.size() < 2)
				return (std::cerr << "Erreur: pas assez d'opérandes pour l'opération.\n", 1);
			int operand2 = s.top();
			s.pop();
			int operand1 = s.top();
			s.pop();
			int result = 0;
			if (std::strcmp(token, "+") == 0)
				result = operand1 + operand2;
			else if (std::strcmp(token, "-") == 0)
				result = operand1 - operand2;
			else if (std::strcmp(token, "*") == 0)
				result = operand1 * operand2;
			else if (std::strcmp(token, "/") == 0)
			{
				if (operand2 == 0)
					return (std::cerr << "Erreur: division par zéro.\n", 1);
				result = operand1 / operand2;
			}
			else
				return (std::cerr << "Erreur: opérateur non reconnu.\n", 1);
			s.push(result);
		}
		token = std::strtok(NULL, " ");
	}

	if (s.size() != 1)
		return (std::cerr << "Erreur: l'expression n'est pas valide.\n", 1);
	std::cout << "Le résultat est : " << s.top() << std::endl;
	return 0;
}
