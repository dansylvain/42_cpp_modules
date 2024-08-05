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
Zombie* Zombie::newZombie( std::string name )
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}

void	Zombie::randomChump( std::string name )
{
	Zombie zombie(name);
	zombie.announce();
}

void Zombie::announce(void) const
{
	std::cout << this->name << ": " << this->mssg << std::endl;
}
