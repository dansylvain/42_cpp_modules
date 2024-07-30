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
(void)src;
return (*this);
}

Brain::~Brain() {

}

std::string& Brain::getIdea() {
	return ideas[std::rand() % 100];
}