#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

/**========================================================================
 *                           ZOMBIE
 *========================================================================**/
class Zombie {
	private:
		std::string	name;
		std::string	mssg;
	public:
		// constructors & destructor
		Zombie();
		Zombie(const std::string& name);
		~Zombie();

		// other methods
		void	announce(void);
		static Zombie*	zombieHorde( int N, std::string name );
		void	set_name(std::string name);
};

#endif