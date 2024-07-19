#include "Zombie.hpp"


Zombie*	zombieHorde( int N, std::string name )
{
	Zombie* zombies = new Zombie[N];

	for ( int i = 0; i < N; i++)
		zombies[i] = Zombie(name);
	return zombies;
}

// void	delete_zombies( int N, Zombie *horde)
// {
// 	for ( int i = 0; i < N; i++ )
// 		delete (horde[i++]);
// }
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
	{
		horde[i].announce();
	}
	return (0);
}