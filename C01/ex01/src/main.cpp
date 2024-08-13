#include "Zombie.hpp"
Zombie	*zombieHorde( int N, std::string name );

/**========================================================================
 *                           MAIN
 *========================================================================**/
int main(int argc, char **argv)
{
	if (argc != 1)
		return (std::cout << "Usage: ./horde" << std::endl, 1);
	Zombie *horde;

	horde = NULL;
	horde = zombieHorde(42, "Zombina");
	for (int i = 0; i < 42; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
	(void)argv;
}