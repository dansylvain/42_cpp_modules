#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "main.hpp"

class Brain
{
	private:
		std::string 	ideas[100];
	public:
		Brain();
		Brain(const Brain *other);
		Brain& operator=(const Brain& src);
		~Brain();

		std::string* getIdeas();
		std::string& getIdea();
};

#endif