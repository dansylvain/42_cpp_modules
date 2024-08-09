#include "AForm.hpp"

class Intern
{	
	public:
		Intern();
		Intern(const Intern& intern);
		Intern& operator=(const Intern& other);
		~Intern();
		AForm* makeForm() const;
};