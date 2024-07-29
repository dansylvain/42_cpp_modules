#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public ClapTrap, virtual public ScavTrap, virtual public FragTrap {
	protected:
		std::string			Name;
		int					HitPoints;
		int					EnergyPoints;
		int					AttackDamage;
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

		// using	ClapTrap::getName;
		using	FragTrap::getHitPoints;
		using	ScavTrap::getEnergyPoints;
		using	FragTrap::getAttackDamage;

		// getters and setters
		virtual const std::string		&getName(void)			const;
		virtual const int				&getHitPoints(void)		const;
		virtual const int				&getEnergyPoints(void)	const;
		virtual const int				&getAttackDamage(void)	const;
		using							ClapTrap::setHitPoints;
};

#endif