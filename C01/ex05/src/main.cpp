#include "Harl.hpp"

void	print(std::string str)
{
	std::cout << str << std::flush;
}

int main(int argc, char **argv)
{
	if (argc != 1)
		return (std::cout << "Usage ./harl" << std::endl, 1);
	Harl harl;
	print("debug:		");
	harl.complain("debug");
	print("\ninfo:		");
    harl.complain("info");
	print("\nwarning:	");
    harl.complain("warning");
	print("\nerror:		");
    harl.complain("error");
	print("\nunknown:	");
    harl.complain("unknown");
	(void)argv;
	return 0;
}