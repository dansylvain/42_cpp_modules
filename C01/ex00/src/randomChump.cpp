#include "Zombie.hpp"

/**========================================================================
 *                           RANDOMCHUMP
 *========================================================================**/
void	randomChump( std::string name )
{
	Zombie zombie(name);
	zombie.announce();
}