#include "Brain.hpp"
#include <ctime>
#include <cstdlib>

Brain::Brain() {
}

Brain::Brain(const Brain &other)  {
(void)other;
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