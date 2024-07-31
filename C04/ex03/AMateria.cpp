#include "AMateria.hpp"

AMateria(std::string const & type);
std::string const & getType() const;
virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);