#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie* zombies = new Zombie[N];

	for ( int i = 0; i < N; i++)
		zombies[i].set_name(name);
	return zombies;
	(void)name;
}

/**========================================================================
 *                           MAIN
 * Tyrone
 *========================================================================**/
int main(void)
{
	Zombie zombie("Bub");
	Zombie *horde;

	horde = NULL;
	zombie.announce();
	horde = zombieHorde(42, "Zombina");
	for ( int i = 0; i < 42; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}