#include "AMateria.hpp"

AMateria	*AMateria::materias[100] = {NULL};
int			AMateria::materiaCount = 0;

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
AMateria::AMateria() : type(new std::string("turlututu"))
{
	print("AMateria Created (default constructor)");
}

AMateria::AMateria(std::string const & type) : type(new std::string(type))
{
	print("AMateria Created (parameter constructor)");
}

AMateria::AMateria(const AMateria& other) : type(new std::string(*other.type))
{
	print("AMateria Created (copy constructor)");
}

AMateria::~AMateria()
{
	delete type;	
	print("AMateria destroyed");
}


/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		print("AMateria copied");
		*type = *other.type;
	}
	return (*this);
}

/**========================================================================
 *                           GETTERS AND SETTERS
 *========================================================================**/
std::string const & AMateria::getType() const
{
	static std::string empty;
	if (type)
		return (*type);
	return (empty);
}

void AMateria::addMateria(AMateria *newMateria)
{
	if (materiaCount < 100) {
        materias[materiaCount++] = newMateria;
    }
}

void	AMateria::cleanup()
{
	for (int i = 0; i < AMateria::materiaCount; ++i) {
        delete materias[i];
    }

	for (int i = 0; i < 100; ++i) {
        materias[i] = NULL;
    }
    materiaCount = 0;
}
/**========================================================================
 *                                ACTION METHODS
 *========================================================================**/
void AMateria::use(ICharacter& target)
{
	(void)target;
}
