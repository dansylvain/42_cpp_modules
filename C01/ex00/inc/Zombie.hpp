#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

/**========================================================================
 *                           ZOMBIE
 *========================================================================**/
class Zombie
{
	private:
		std::string	name;
		std::string	mssg;
	public:
		// constructor & destructor
		Zombie();
		Zombie(const std::string& name);
		~Zombie();

		// methods
		void	announce() const;
};

#endif