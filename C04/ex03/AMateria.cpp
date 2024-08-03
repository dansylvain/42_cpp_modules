#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

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

AMateria *AMateria::addMateria(AMateria *newMateria)
{
	if (materiaCount < 100) {
		newMateria->loc = GROUND;
		materias[materiaCount++] = newMateria;
	}
	return (newMateria);
}

AMateria*	AMateria::addMateria(std::string type)
{
	AMateria *ptr;
	if (type == CURE)
		ptr = AMateria::addMateria(new Cure(type));
	else if (type == ICE)
		ptr = AMateria::addMateria(new Ice(type));
	return (ptr);
	
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

std::string const & AMateria::getLoc() const
{
	return (loc);
}

void AMateria::setLoc(std::string newLoc)
{
	loc = newLoc;
}
/**========================================================================
 *                                ACTION METHODS
 *========================================================================**/
void AMateria::use(ICharacter& target)
{
	(void)target;
}

void	AMateria::displayMaterias()
{
	for (int i = 0; i < materiaCount; i++)
	{
		if(materias[i]->getLoc() == GROUND)
			print(materias[i]->getType() + ", loc: " + materias[i]->getLoc());
	}
}
