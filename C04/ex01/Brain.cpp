#include "Brain.hpp"


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
