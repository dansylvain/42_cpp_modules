#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;
	public:
		//constructor and destructor
		Form();
		Form(const std::string	_name, const int gradeToSign, const int gradeToExec);
		Form(const Form& other);
		~Form();

		//assignment operator
		Form& operator=(const Form& other);


		//getters and setters
		const std::string&	get_name() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		void				beSigned(Bureaucrat& bureaucrat);
		void				setSignedToTrue();


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
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif