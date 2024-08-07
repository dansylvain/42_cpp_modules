#include "Bureaucrat.hpp"
#include "main.hpp"
//		const std::string	name;
//		int					grade;
		// constructors and destructor

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
	print("Bureaucrat destroyed");
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

/**========================================================================
 *                           GETTERS AND SETTERS
 *========================================================================**/
const std::string&	Bureaucrat::getName() const 
{
	return (_name);
}

int					Bureaucrat::getGrade() const
{
	return (_grade);
}

void				Bureaucrat::incrementGrade()
{
	if (_grade >= 150)
		throw GradeTooHighException();
	_grade++;
}

void				Bureaucrat::decrementGrade()
{
	if (_grade <= 0)
		throw GradeTooLowException();
	_grade--;
}

/**========================================================================
 *                           EXCEPTIONS
 *========================================================================**/
const char* 		Bureaucrat::GradeTooHighException::what() const throw() 
{
	return ("Grade too high");
}

const char* 		Bureaucrat::GradeTooLowException::what() const throw() 
{
	return ("Grade too low");
}

