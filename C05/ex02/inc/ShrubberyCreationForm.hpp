#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string	_name);
		ShrubberyCreationForm(const AForm& other);
		~ShrubberyCreationForm();
		void				setSignedToTrue();
};