#include "Brain.hpp"
#include <ctime>
#include <cstdlib>

Brain::Brain() {
}

Brain::Brain(const Brain *other) {
	for (int i = 0; i < 100; i++)
		ideas[i] = (*other).ideas[i];
	print("brain transplanted");
}

Brain& Brain::operator=(const Brain& src) {
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = src.ideas[i];
		print("brain transplanted");
	}
	return (*this);
}

Brain::~Brain() {
	print("Brain desintegrated");
}

std::string& Brain::getIdea() {
	return ideas[std::rand() % 100];
}

std::string* Brain::getIdeas()
{
	return (&ideas[0]);
}