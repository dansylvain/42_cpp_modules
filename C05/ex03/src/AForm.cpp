#include "AForm.hpp"
#include "main.hpp"
#include <sstream>
#include "Bureaucrat.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
AForm::AForm() : _name("form"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "AForm " << _name << " created (default constructor)" << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec) :	_name(name),
																				_isSigned(false),
																				_gradeToSign(gradeToSign),
																				_gradeToExec(gradeToExec)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooHighException();
	if (gradeToSign < 0 || gradeToExec < 0)
		throw GradeTooLowException();
	std::cout << "AForm " << _name << " created (parametered constructor)" << std::endl;
}

AForm::AForm(const AForm& other) :	_isSigned(other._isSigned),
							_gradeToSign(other._gradeToSign),
							_gradeToExec(other._gradeToExec)
{
	print("AForm created (copy constructor)");
}

AForm::~AForm()
{
	print("AForm destroyed");
}

/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	std::string str;
	if (form.getIsSigned())
		str = "signed, ";
	else 
		str = "NOT signed, ";
	os << form.get_name() << ", " + str
	<< "grade needed to sign: "
	<< form.getGradeToSign()
	<< ", grade needed to execute: "
	<< form.getGradeToExec();
	return os;
}

/**========================================================================
 *                           GETTERS AND SETTERS
 *========================================================================**/
const std::string&	AForm::get_name() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExec() const
{
	return (_gradeToExec);
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		std::cout << bureaucrat.get_name() << " couldn't sign " << _name << " because ";
		throw (GradeTooLowException());
	}
	setSignedToTrue();
	// _isSigned = true;
	std::cout << bureaucrat.get_name() << " signed " << _name << std::endl;
}

void	AForm::setSignedToTrue()
{
	_isSigned = true;
}

int	AForm::execute(const Bureaucrat& executor) const
{
	if (!_isSigned)
	{
		std::cout << executor.get_name() << " could not execute " << get_name() << ": " << std::endl;
		throw (FormNotSignedException());
	}

	if (executor.getGrade() > _gradeToExec)
	{
		std::cout << executor.get_name() << " could not execute " << get_name() << ": " << std::endl;
		throw (GradeTooLowException());
	}
	std::cout << executor.get_name() << " executed " << this->get_name() << std::endl;

	action();
	return (1);
}

/**========================================================================
 *                           EXCEPTIONS
 *========================================================================**/
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

