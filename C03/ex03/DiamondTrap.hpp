#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"	
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string			_Name;
		int					_HitPoints;
		int					_EnergyPoints;
		int					_AttackDamage;
	public:
		// Constructors and destructor
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap();

		// assignment operator
		DiamondTrap &operator=(const DiamondTrap &src);

		// other methods
		void whoAmI();
		void initialize(void);
};

#endif