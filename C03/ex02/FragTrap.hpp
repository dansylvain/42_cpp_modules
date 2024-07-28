#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP


#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
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
};

#endif