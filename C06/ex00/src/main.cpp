#include "ScalarConverter.hpp"

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