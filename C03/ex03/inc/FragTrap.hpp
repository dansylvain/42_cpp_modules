#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP


#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	protected:
		std::string			Name;
		int					HitPoints;
		int					EnergyPoints;
		int					AttackDamage;
	public:
		// Constructors and destructor
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap &other);
		~FragTrap();

		// assignment operator
	    FragTrap& operator=(const FragTrap& src);

		// action methods
		void	attack(const std::string& target);
		void	highFivesGuys(void) const;

		// utils methods
		void	DisplayName(std::string str) const;
		void	initialize(std::string str);

		// using	ClapTrap::getName;
		// using	ClapTrap::getHitPoints;
		// using	ClapTrap::getEnergyPoints;
		// using	ClapTrap::getAttackDamage;
		

		// getters and setters
		virtual const std::string		&getName(void)			const;
		virtual const int				&getHitPoints(void)		const;
		virtual const int				&getEnergyPoints(void)	const;
		virtual const int				&getAttackDamage(void)	const;
		// using							ClapTrap::setHitPoints;
		virtual void					setHitPoints(int num);

};

#endif