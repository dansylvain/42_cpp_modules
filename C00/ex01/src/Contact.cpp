#include "Contact.hpp"

void	Contact::setFirstName(std::string firstName)
		{Contact::_firstName = firstName;}
void	Contact::setLastName(std::string lastName)
		{Contact::_lastName = lastName;}
void	Contact::setNickname(std::string nickname)
		{Contact::_nickname = nickname;}
void	Contact::setPhoneNumber(std::string phoneNumber)
		{Contact::_phoneNumber = phoneNumber;}
void	Contact::setDarkestSecret(std::string darkestSecret)
		{Contact::_darkestSecret = darkestSecret;}

std::string	Contact::getFirstName(void) const {return (this->_firstName);}
std::string	Contact::getLastName(void) const {return (Contact::_lastName);}
std::string	Contact::getNickname(void) const {return (Contact::_nickname);}
std::string	Contact::getPhoneNumber(void) const {return (Contact::_phoneNumber);}
std::string	Contact::getDarkestSecret(void) const {return (Contact::_darkestSecret);}
