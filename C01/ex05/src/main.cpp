#include "Harl.hpp"

void	print(std::string str)
{
	std::cout << str << std::flush;
}

int main(void)
{
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
	return 0;
}