#include "Terminal.hpp"
#include <iostream>


/**========================================================================
 *                           PHONEBOOK
 * for increased portability, checks could be carried out to ensure that the
 * system is running a Unix-like system before executing the command.
 * But since this app will run at 42 only, 
 * we can be sure that the system is Unix-like...
 *========================================================================**/
int main(int argc, char **argv)
{
	Terminal term;

	if (argc == 1)
		term.execSystemCmd(term.terminalCommand);
	else
		std::cout << "Usage: ./exec" << std::endl;
	
	return 0;
	(void)argv;
}