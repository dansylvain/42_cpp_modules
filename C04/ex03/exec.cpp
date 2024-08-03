#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void	print(std::string str);
void	printB(const std::string& str);
void printFB(const std::string& str);

void	printF(std::string str);
void	test_one();
void	test_two();
void	test_three();

bool TEST;




int main()
{
	TEST = false;
	// std::string c;
	// while (c != "1" && c != "2")
	// {
	// 	std::cout << "test 1 or 2? ";
	// 	std::cin >> c; 
	// }
	// switch (c[0])
	// {
	// 	case '1':
	// 		test_one();
	// 		break;
	// 	case '2' :
	// 		test_two();
	// 		break;
	// 	default :
	// 		print("Fuck off");
	// 		break;
	// }
	test_three();
	return 0;
}

void	print(std::string str)
{
	if (TEST)
		std::cout << str << std::endl;
}

void printB(const std::string& str)
{
	if (TEST)
    	std::cout << "\033[1;32m" << str << "\033[0m" << std::endl;
}

void	printF(std::string str)
{
		std::cout << str << std::endl;
}

void printFB(const std::string& str)
{
   	std::cout << "\033[1;32m" << str << "\033[0m" << std::endl;
}