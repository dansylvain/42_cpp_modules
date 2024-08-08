#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 147, 137)
{
	std::cout << "ShrubberyCreationForm " << _name << " created (default constructor)" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string	_name) : AForm(_name, 147, 137)
{
	std::cout << "ShrubberyCreationForm " << _name << " created (parametered constructor)" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const AForm& other) :	AForm(other.get_name(), 
																	other.getGradeToSign(),
																	other.getGradeToExec())
{
	std::cout << "ShrubberyCreationForm " << _name << " created (copy constructor)" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << _name << " destroyed" << std::endl;
}

void				ShrubberyCreationForm::setSignedToTrue()
{

}