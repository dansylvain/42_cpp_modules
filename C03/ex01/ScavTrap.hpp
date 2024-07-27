#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP


#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap() : ClapTrap() { std::cout << "ScavTrap " << this->getName() << " created" << std::endl;};
		ScavTrap(const std::string& name) : ClapTrap(name) { std::cout << "ScavTrap " << this->getName() << " created" << std::endl;};
		ScavTrap(const ScavTrap &other) : ClapTrap(other) { std::cout << "ScavTrap " << this->getName() << " created" << std::endl;};
		~ScavTrap() { std::cout << "ScavTrap " << this->getName() << " destroyed" << std::endl;};

		// assignment operator
	    ScavTrap& operator=(const ScavTrap& src);
		void guardGate();
};

#endif