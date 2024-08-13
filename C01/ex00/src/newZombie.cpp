#include "Zombie.hpp"

/**========================================================================
 *                           NEWZOMBIE
 *========================================================================**/
Zombie*	newZombie( std::string name )
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}