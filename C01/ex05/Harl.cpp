#include "Harl.hpp"

/**========================================================================
 *                           CONSTRUCTOR
 *========================================================================**/
Harl::Harl() :
	_debugMssg("I love having extra bacon for my 7XL-double-cheese-\
triple-pickle-special-ketchup burger. I really do!"),
	_infoMssg("I cannot believe adding extra bacon costs more money. \
You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"),
	_warningMssg("I think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since last month."),
	_errorMssg("This is unacceptable! I want to speak to the manager now.")
{}

Harl::~Harl() {}

void Harl::debug( void )
{
	std::cout << Harl::_debugMssg << std::endl;
}

void Harl::info( void )
{
	std::cout << Harl::_infoMssg << std::endl;
}

void Harl::warning( void )
{
	std::cout << Harl::_warningMssg << std::endl;
}

void Harl::error( void )
{
	std::cout << Harl::_errorMssg << std::endl;
}

/**========================================================================
 *                           COMPLAIN
 *========================================================================**/
void Harl::complain( std::string level )
{
	FunctionMap functionMap[] = {
	{"debug", &Harl::debug},
	{"info", &Harl::info},
	{"warning", &Harl::warning},
	{"error", &Harl::error}
	};

	for (int i = 0; i < 4; ++i)
	{
		if (level == functionMap[i].name)
		{
			(this->*(functionMap[i].function))();
			return;
		}
	}
	std::cout << "Unknown level" << std::endl;
}

