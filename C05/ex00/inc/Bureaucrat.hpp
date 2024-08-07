#include <iostream>

class Bureaucrat{
	private:
		const std::string	name;
		int					grade;
	public:
		// constructors and destructor
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		// assignment operateur
		Bureaucrat& operator=(const Bureaucrat& other);

		// getters and setters
		const std::string&	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
};