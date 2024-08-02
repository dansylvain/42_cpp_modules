#include "AMateria.hpp"

AMateria	*AMateria::materias[100] = {NULL};
int			AMateria::materiaCount = 0;

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
AMateria::AMateria() : type(new std::string("turlututu")), free(new bool(true))
{
	print("AMateria Created (default constructor)");
}

AMateria::AMateria(std::string const & type) : type(new std::string(type)), free(new bool(true))
{
	print("AMateria Created (parameter constructor)");
}

AMateria::AMateria(const AMateria& other) : type(new std::string(*other.type)), free(new bool(other.free))
{
	print("AMateria Created (copy constructor)");
}

AMateria::~AMateria()
{
	delete type;
	delete free;
	
	
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
		*free = *other.free;
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

bool	const & AMateria::isFree() const
{
	return (*free);
}

void	AMateria::toggleMateriaAvailability()
{
	// std::cout << "before: " << *free;
	*free ? *free = 0 : *free = 1;
	// std::cout << ", after: " << *free <<std::endl;
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
		print("*************deleting**************");
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
