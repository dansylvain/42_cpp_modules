#include "PresidentialPardonForm.hpp"
#include "main.hpp"
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm " << _name << " created (default constructor)" << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(const std::string	_name) : AForm(_name, 25, 5)
{
	std::cout << "PresidentialPardonForm " << _name << " created (parametered constructor)" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const AForm& other) :	AForm(other.get_name(), 
																	other.getGradeToSign(),
																	other.getGradeToExec())
{
	std::cout << "PresidentialPardonForm " << _name << " created (copy constructor)" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << _name << " destroyed" << std::endl;
}

void				PresidentialPardonForm::setSignedToTrue()
{
	_isSigned = true;
	print("*************** PresidentialPardonForm DO SOMETHING *************");
}