#include "RobotomyRequestForm.hpp"
#include "main.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("target")
{
	std::cout << "RobotomyRequestForm " << _name << " created (default constructor)" << std::endl;
	std::srand(std::time(0));
}


RobotomyRequestForm::RobotomyRequestForm(const std::string	name, const std::string target) : AForm(name, 72, 45), _target(target)
{
	std::srand(std::time(0));
	std::cout << "RobotomyRequestForm " << _name << " created (parametered constructor)" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :	AForm(other.get_name(), 
																	other.getGradeToSign(),
																	other.getGradeToExec()), _target(other._target)
{
	std::srand(std::time(0));
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
	std::cout << "Drilling noises..." << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy of " << _target << " failed." << std::endl;
}