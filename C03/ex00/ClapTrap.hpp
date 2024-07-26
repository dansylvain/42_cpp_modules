#include <iostream>

class ClapTrap {
	private:
		std::string		Name;
		int				HitPoints; // 10
		int				EnergyPoints; //10
		int				AttackDamage; // 0
	public:
		// Constructors and destructor
		ClapTrap();
		ClapTrap(const std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap &other);

		// assignment operator
		ClapTrap &operator=(const ClapTrap &src);
		
		// getters and setters
		std::string		getName(void)			const;
		int				getHitPoints(void)		const;
		int				getEnergyPoints(void)	const;
		int				getAttackDamage(void)	const;

		// other methods
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};