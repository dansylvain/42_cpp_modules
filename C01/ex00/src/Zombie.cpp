#include "Zombie.hpp"

/**========================================================================
 *                           CONSTRUCTOR & DESTRUCTOR
 *========================================================================**/
Zombie::Zombie() : name("Unnamed"), mssg("BraiiiiiiinnnzzzZ...") {};

Zombie::Zombie(const std::string& name) : name(name), mssg("BraiiiiiiinnnzzzZ...") {};

Zombie::~Zombie()
{
	std::cout << this->name << " was destroyed" << std::endl;
}

/**========================================================================
 *                           OTHER METHODS
 *========================================================================**/

void	Zombie::announce() const
{
	std::cout << this->name << ": " << this->mssg << std::endl;
}
