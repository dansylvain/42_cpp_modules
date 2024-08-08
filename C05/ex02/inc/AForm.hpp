#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;
	public:
		//constructor and destructor
		AForm();
		AForm(const std::string	_name, const int gradeToSign, const int gradeToExec);
		AForm(const AForm& other);
		~AForm();

		//assignment operator
		AForm& operator=(const AForm& other);

		friend std::ostream& operator<<(std::ostream& os, const AForm& form);

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

#endif