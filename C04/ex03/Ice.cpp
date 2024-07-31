#include "Ice.hpp"

Ice::Ice(std::string const & type) : AMateria() {
	(void)type;
}

Ice::Ice(const Ice &other) : AMateria() {
	(void)other;
}

Ice& Ice::operator=(const Ice& other) {
	(void)other;
	return (*this);
}

Ice::~Ice() {

}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	(void)target;
}

