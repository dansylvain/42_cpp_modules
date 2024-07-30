#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain {
	private:

	public:
		std::string 	ideas[100];
		Brain();
		Brain(const Brain &other);
		Brain& operator=(const Brain& src);
		~Brain(); 
};

#endif