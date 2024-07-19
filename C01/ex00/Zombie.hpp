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
		void announce(void);
};

#endif