#include <iostream>
#include <string>

class ScalarConverter
{
	private:

		ScalarConverter(const ScalarConverter& other);
		virtual const ScalarConverter& operator=(const ScalarConverter& rhs) = 0;
	public:
		ScalarConverter();
		~ScalarConverter();

		static void	convert(const std::string& str);
};