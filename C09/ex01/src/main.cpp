#include "main.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
		return (std::cout << "Usage: ./RPN <expression>" << std::endl, 1);

	std::cout << "Welcome to the jungle: " << argv[1] << std::endl;
	return (0);
}