#include "RobotomyRequestForm.hpp"
#include "main.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("target")
{
	std::cout << "RobotomyRequestForm " << _name << " created (default constructor)" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(const std::string	name, const std::string target) : AForm(name, 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm " << _name << " created (parametered constructor)" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :	AForm(other.get_name(), 
																	other.getGradeToSign(),
																	other.getGradeToExec()), _target(other._target)
{
	std::cout << "RobotomyRequestForm " << _name << " created (copy constructor)" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << _name << " destroyed" << std::endl;
}

void	RobotomyRequestForm::setSignedToTrue()
{
	_isSigned = true;
}

void	RobotomyRequestForm::action() const
{
	std::cout << "****** RobotomyRequestForm *********** " << _target << std::endl;	
}