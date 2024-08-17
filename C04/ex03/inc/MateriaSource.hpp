/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:38:16 by dsylvain          #+#    #+#             */
/*   Updated: 2024/08/17 10:38:16 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource
{
	private:
		static AMateria*		inv[4];
	public:
		// constructors and destructor
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		virtual ~MateriaSource();

		// assignment operator
		MateriaSource& operator=(const MateriaSource& other);

		// getters and setters
		static	AMateria	**getInv();

		// action methods
		virtual void 		learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const & type);

		// utils methods
		void				initInv();
		static void			displayMaterias();
		static void			displayMateriaCount();
};

#endif

