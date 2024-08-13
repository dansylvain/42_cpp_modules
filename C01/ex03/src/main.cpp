#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(int argc, char **argv)
{
	if (argc != 1)
		return (std::cout << "Usage: ./be_violent" << std::endl, 1);
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(&club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
	(void)argv;
}
