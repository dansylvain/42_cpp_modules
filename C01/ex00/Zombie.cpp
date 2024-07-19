#include "Zombie.hpp"



Zombie::Zombie() : name("Unnamed"), mssg("BraiiiiiiinnnzzzZ...") {};

Zombie::Zombie(const std::string& name) : name(name), mssg("BraiiiiiiinnnzzzZ...") {};

void Zombie::announce(void)
{
	std::cout << this->name << ": " << this->mssg << std::endl;
}


int main(void)
{
	Zombie zombie("foo");

	zombie.announce();
	return (0);
}