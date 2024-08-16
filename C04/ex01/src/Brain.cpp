#include "main.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
Brain::Brain()
{
	print("brain created");
}

Brain::Brain(const Brain *other)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = (*other).ideas[i];
	print("brain copied");
}

Brain::~Brain()
{
	print("Brain desintegrated");
}

/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
Brain& Brain::operator=(const Brain& src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = src.ideas[i];
		print("brain copied");
	}
	return (*this);
}

/**========================================================================
 *                           GETTERS AND SETTERS>
 *========================================================================**/
std::string& Brain::getIdea()
{
	return ideas[std::rand() % 100];
}

std::string* Brain::getIdeas()
{
	return (&ideas[0]);
}
