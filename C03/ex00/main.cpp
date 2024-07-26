#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Bobby");
	ClapTrap b("Lucy");
	ClapTrap c("Fahrid");
	ClapTrap d("Clarence");
	ClapTrap e("Karim");
	for (int i = 0; i < ClapTrap::count; i++)
		std::cout << ClapTrap::allClapTraps[i]->getName() << std::endl;
	std::cout << "Hello world!" <<std::endl;
	return (0);
}