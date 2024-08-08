#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string	_name);
		PresidentialPardonForm(const AForm& other);
		~PresidentialPardonForm();
		void				setSignedToTrue();
};