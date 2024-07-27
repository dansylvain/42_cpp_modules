#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP


#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap() : ClapTrap() {};
		ScavTrap(const std::string& name) : ClapTrap(name) {};
		ScavTrap(const ScavTrap &other) : ClapTrap(other) {};
		~ScavTrap() {};

		// assignment operator
	    ScavTrap& operator=(const ScavTrap& src);
		void guardGate();
};

#endif