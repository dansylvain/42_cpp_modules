/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:38:56 by dsylvain          #+#    #+#             */
/*   Updated: 2024/08/17 10:38:56 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
Cure::Cure() : AMateria(), id(new int(AMateria::materiaCount)), loc(new std::string(GROUND))
{
	*type = CURE;
	print("Cure created (default constructor)");
}

Cure::Cure(std::string const & type) : AMateria(), id(new int(AMateria::materiaCount)), loc(new std::string(GROUND))
{
	*Cure::type = type;
	print("Cure created (parameter constructor)");
}

Cure::Cure(const Cure& other) : AMateria(other), id(new int(AMateria::materiaCount)), loc(new std::string(GROUND))
{
	print("Cure created (copy constructor)");
}

Cure::~Cure()
{
	delete id;
	delete loc;
	print("Cure destroyed");
}

/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
		print("Cure copied");
		AMateria::operator=(other);
	}
	return (*this);
}

/**========================================================================
 *                                ACTION METHODS
 *========================================================================**/
AMateria* Cure::clone() const
{
	AMateria* ptr = new Cure(*this);
	AMateria::addMateria(ptr);
	ptr->setLoc(GROUND);
	print("Cure cloned");
	return (ptr);
}

void Cure::use(ICharacter& target)
{
	print("* heals " + target.getName() + "’s wounds *");
	(void)target;
}