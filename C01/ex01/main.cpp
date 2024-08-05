#include "Zombie.hpp"

/**========================================================================
 *                           MAIN
 *========================================================================**/
int main(void)
{
	Zombie *horde;
	Zombie zombie("Bub");

	horde = NULL;
	zombie.announce();
	horde = Zombie::zombieHorde(42, "Zombina");
	for (int i = 0; i < 42; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}