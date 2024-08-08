#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string	_name);
		RobotomyRequestForm(const AForm& other);
		~RobotomyRequestForm();
		void				setSignedToTrue();
};