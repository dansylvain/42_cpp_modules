#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP


#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();

		// assignment operator
	    ScavTrap& operator=(const ScavTrap& src);
		void attack(const std::string& target);
		void guardGate();
};

#endif