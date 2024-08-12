#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void	randomChump( std::string name );
/**========================================================================
 *                           MAIN
 *========================================================================**/
int main(void)
{
	Zombie zombie("Bub");
	zombie.announce();

	Zombie *Zombina = newZombie("Zombina");
	Zombina->announce();
	
	randomChump("Tyrone");
	delete Zombina;
	return (0);
}