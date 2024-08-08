#include "ShrubberyCreationForm.hpp"
#include "main.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 147, 137), _target("target")
{
	std::cout << "ShrubberyCreationForm " << _name << " created (default constructor)" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const std::string target) : AForm(name, 147, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm " << _name << " created (parametered constructor)" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :	AForm(other.get_name(), 
																	other.getGradeToSign(),
																	other.getGradeToExec()), _target(other._target)
{
	std::cout << "ShrubberyCreationForm " << _name << " created (copy constructor)" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << _name << " destroyed" << std::endl;
}

void				ShrubberyCreationForm::setSignedToTrue()
{
	std::cout << "****** ShrubberyCreationForm *********** " << _target << std::endl;
}
