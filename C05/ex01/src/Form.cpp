#include "Form.hpp"
#include "main.hpp"
#include <sstream>

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
Form::Form() : _name("Form"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	print("Form created (default constructor)");
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) :	_name(name),
																				_isSigned(false),
																				_gradeToSign(gradeToSign),
																				_gradeToExec(gradeToExec)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooHighException();
	if (gradeToSign < 0 || gradeToExec < 0)
		throw GradeTooLowException();
	print("Form created (parametered constructor)");
}

Form::Form(const Form& other) :	_isSigned(other._isSigned),
							_gradeToSign(other._gradeToSign),
							_gradeToExec(other._gradeToExec)
{
	print("Form created (copy constructor)");
}

Form::~Form()
{
	print("Form destroyed");
}

/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	std::string str;
	if (form.getIsSigned())
		str = "signed, ";
	else 
		str = "NOT signed, ";
	os << form.get_name() << ", " + form.getIsSigned() + str << "grade to sign: "
	<< form.getGradeToSign() << ", grade to execute: " << form.getGradeToExec();
		return os;
}

const std::string&	Form::get_name() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (_gradeToExec);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

