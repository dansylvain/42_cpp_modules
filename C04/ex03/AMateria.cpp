#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iomanip>

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
AMateria	**AMateria::getMaterias()
{
	return (materias);
}

int	AMateria::getMateriaCount()
{
	return (materiaCount);
}

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
	int count = materiaCount;
	if (count == 2)
		count = 4;
	for (int i = 0; i < count; i++)
	{
		if (materias[i]->getType() == ICE && materias[i]->getLoc() == GROUND)
				std::cout << "🧊 ";
		else if (materias[i]->getType() == CURE &&materias[i]->getLoc() == GROUND)
			std::cout << "💚 ";
		else
			std::cout << "   ";
	}
}

void	AMateria::displayMateriaCount()
{
	for (int i = 0; i < materiaCount; i++)
	{
		if (materias[i]->getLoc() == GROUND)
			std::cout << std::setw(2) << std::setfill(' ') << i << " ";
		else
			std::cout << "   ";

	}
}

int	AMateria::getGroundSize()
{
	int j = 0;
	for (int i = 0; i < materiaCount; i++)
	{
		if (materias[i]->getLoc() == GROUND)
			j++;
	}
	return (j);

}
// for (int i = 0; i < 4; i++)
// 	{
// 		if (inv[i])
// 		{
// 			if (materias[i]->getType() == ICE)
// 				std::cout << "🧊 ";
// 			else if (materias[i]->getType() == CURE)
// 				std::cout << "💚 ";

// 		}
// 	}
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (inv[i])
// 			std::cout << i << "  ";
// 	}