#include <iostream>

void	print(std::string str);

int	main(void)
{
	print("Welcome to the Jungle");
	return (0);
}

void	print(std::string str)
{
	std::cout << str << std::endl;
}