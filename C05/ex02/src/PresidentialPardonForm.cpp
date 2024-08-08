#include "PresidentialPardonForm.hpp"
#include "main.hpp"
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("target")
{
	std::cout << "PresidentialPardonForm " << _name << " created (default constructor)" << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(const std::string name, std::string target) : AForm(name, 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm " << _name << " created (parametered constructor)" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :	AForm(other.get_name(), 
																	other.getGradeToSign(),
																	other.getGradeToExec()),
																	_target(other._target)
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
}

void	PresidentialPardonForm::action() const
{
	std::cout << "****** PresidentialPardonForm *********** " << _target << std::endl;	
}