#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP


#include "ClapTrap.hpp"

class DiamondTrap : public ClapTrap {
	public:
		// Constructors and destructor
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap();

		// assignment operator
	    DiamondTrap& operator=(const DiamondTrap& src);

		// action methods
		void	attack(const std::string& target);
		void	guardGate() const;

		// utils methods
		void	DisplayName(std::string str) const;
		void	initialize(std::string str);
};

#endif