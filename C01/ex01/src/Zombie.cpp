#include "Zombie.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
Zombie::Zombie() : name("Unnamed"), mssg("BraiiiiiiinnnzzzZ...") {
	std::cout << this->name << " was created" << std::endl;
}

Zombie::Zombie(const std::string& name) : name(name), mssg("BraiiiiiiinnnzzzZ...") {
	std::cout << this->name << " was created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " was destroyed" << std::endl;
}
/**========================================================================
 *                           OTHER METHODS
 *========================================================================**/
void Zombie::announce(void)
{
	std::cout << this->name << ": " << this->mssg << std::endl;
}

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

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

Zombie	*Zombie::zombieHorde( int N, std::string name )
{
	Zombie	*Horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		Horde[i].set_name(name);
	return Horde;
}