#include "Harl.hpp"

/**========================================================================
 *                           CONSTRUCTOR
 *========================================================================**/
Harl::Harl() :
	_debugMssg("[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-\n\
triple-pickle-special-ketchup burger. I really do!\n"),
	_infoMssg("[ INFO ]\nI cannot believe adding extra bacon costs more money. \n\
You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"),
	_warningMssg("[ WARNING ]\nI think I deserve to have some extra bacon for free. \n\
I’ve been coming for years whereas you started working here since last month.\n"),
	_errorMssg("[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n")
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
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
/**========================================================================
 *                           FILTER
 *========================================================================**/
void	Harl::filter( std::string level )
{
	switch (levelToEnum(level))
	{
	case ERROR:
		complain("error");
		break;
	case WARNING:
		complain("warning");
		complain("error");
		break;
	case INFO:
		complain("warning");
		complain("error");
		complain("info");
		break;
	case DEBUG:
		complain("warning");
		complain("error");
		complain("debug");
		complain("info");
		break;	
	default:
		complain("Unknown level");
		break;
	}
	
}

int		Harl::levelToEnum(std::string level)
{
	if (level == "debug") return DEBUG;
	if (level == "info") return INFO;
	if (level == "warning") return WARNING;
	if (level == "error") return ERROR;
	return UNKNOWN;
}
