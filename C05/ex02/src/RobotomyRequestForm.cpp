#include "RobotomyRequestForm.hpp"
#include "main.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm " << _name << " created (default constructor)" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(const std::string	_name) : AForm(_name, 72, 45)
{
	std::cout << "RobotomyRequestForm " << _name << " created (parametered constructor)" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const AForm& other) :	AForm(other.get_name(), 
																	other.getGradeToSign(),
																	other.getGradeToExec())
{
	std::cout << "RobotomyRequestForm " << _name << " created (copy constructor)" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << _name << " destroyed" << std::endl;
}

void				RobotomyRequestForm::setSignedToTrue()
{
	_isSigned = true;
	print("*************** RobotomyRequestForm DO SOMETHING *************");
}