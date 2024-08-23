#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class AForm
{
	protected:
		std::string	_name;
		bool				_isSigned;
		int			_gradeToSign;
		int			_gradeToExec;
	public:
		//constructor and destructor
		AForm();
		AForm(const std::string	_name, const int gradeToSign, const int gradeToExec);
		AForm(const AForm& other);
		virtual ~AForm();

		//assignment operator
		AForm& operator=(const AForm& other);

		//getters and setters
		virtual const std::string&	get_name() const;
		virtual bool				getIsSigned() const;
		virtual int					getGradeToSign() const;
		virtual int					getGradeToExec() const;
		virtual void				beSigned(Bureaucrat& bureaucrat);
		virtual void				setSignedToTrue() = 0;
		int						execute(const Bureaucrat& executor) const;
		virtual void				action() const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual char const* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual char const* what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		public:
			virtual char const* what() const throw();
	};	
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif