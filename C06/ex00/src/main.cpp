#include "ScalarConverter.hpp"

/**========================================================================
 *                             THE EXERCISE SHOULD BE REDONE
 *  in fact, I have to first detect the type of the literal passed 
 * as parameter, convert it from string to its actual type, then convert
 * it explicitly to the three other data types. Lastly, display 
 * the results as shown below.
 * =======================================================================**/
int main() {
	std::string input;

	while (true) {
		std::cout << "Enter a string representation of a C++ literal in its most common form (or type 'exit' to quit): " << std::flush;
		std::getline(std::cin, input);
		if (input == "exit")
			break;
		if (input.empty())
			continue;
		ScalarConverter::convert(input);
	}

	return 0;
}