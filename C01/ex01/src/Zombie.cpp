#include "Zombie.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
Zombie::Zombie() : name("Unnamed zombie"), mssg("BraiiiiiiinnnzzzZ...") {
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