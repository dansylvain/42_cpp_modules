#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "main.hpp"
class Intern
{	
	public:
		Intern();
		Intern(const Intern& intern);
		Intern& operator=(const Intern& other);
		~Intern();
		FormType getFormType(const std::string formName) const;
		AForm* makeForm(std::string formName, std::string formTarget) const;
};

#endif