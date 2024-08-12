#include "Zombie.hpp"
Zombie	*zombieHorde( int N, std::string name );

/**========================================================================
 *                           MAIN
 *========================================================================**/
int main(void)
{
	Zombie *horde;

	horde = NULL;
	horde = zombieHorde(42, "Zombina");
	for (int i = 0; i < 42; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}