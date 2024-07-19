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
		Zombie();
		Zombie(const std::string& name);
		~Zombie();
		void	announce(void);
		Zombie*	newZombie( std::string name );
		void	randomChump( std::string name );
		Zombie*	zombieHorde( int N, std::string name );
		void	set_name(std::string name);
};

#endif