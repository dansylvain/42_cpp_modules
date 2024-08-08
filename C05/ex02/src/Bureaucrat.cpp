#include "Bureaucrat.hpp"
#include "main.hpp"
#include <sstream>
#include "Form.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150)
{
	print("Bureaucrat created (default constructor)");
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooHighException();
	if (grade < 0)
		throw GradeTooLowException();
	print("Bureaucrat created (parametered constructor)");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	print("Bureaucrat created (copy constructor)");
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
}

/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.get_name() << ", bureaucrat grade " << bureaucrat.getGrade();
		return os;
}


/**========================================================================
 *                           GETTERS AND SETTERS
 *========================================================================**/
const std::string&	Bureaucrat::get_name() const 
{
	return (_name);
}

int		Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooHighException();
	_grade++;
	std::cout << _name << "grade decremented: now at " << _grade << std::endl;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooLowException();
	_grade--;
	std::cout << _name << "grade incremented: now at " << _grade << std::endl;
}

void	Bureaucrat::signForm(Form& form)
{
	if (getGrade() > form.getGradeToSign())
	{
		std::cout << get_name() << " couldn't sign " << form.get_name() << " because ";
		throw (GradeTooLowException());
	}
	std::cout << get_name() << " signed " << form.get_name() << std::endl;
	form.setSignedToTrue();
}

/**========================================================================
 *                           EXCEPTIONS
 *========================================================================**/
const char*	Bureaucrat::GradeTooHighException::what() const throw() 
{
	return ("Grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() 
{
	return ("Grade too low");
}

