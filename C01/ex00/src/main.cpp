#include "Zombie.hpp"

/**========================================================================
 *                           MAIN
 *========================================================================**/
int main(int argc, char **argv)
{
	if (argc != 1)
		return (std::cout << "Usage: ./brainzz" << std::endl, 1);
	Zombie zombie("Bub");
	zombie.announce();

	Zombie *Zombina = newZombie("Zombina");
	Zombina->announce();
	
	randomChump("Tyrone");
	delete Zombina;
	return (0);
	(void)argv;
}