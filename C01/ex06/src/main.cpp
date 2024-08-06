#include "Harl.hpp"

void	print(std::string str)
{
	std::cout << str << std::endl;
}

int main(int argc, char **argv)
{
	Harl harl;
	if (argc == 2)
		harl.filter(argv[1]);
	else
		print("usage: ./harlfilter level");
	return 0;
}


