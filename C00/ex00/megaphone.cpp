#include <iostream>
#include <string>
#include <cctype>

/**========================================================================
 *                           megaphone
 *========================================================================**/
class Megaphone
{
	public:
	void shout(const std::string& input) const
	{
		for (size_t i = 0; i < input.size(); ++i)
			std::cout << static_cast<char>(std::toupper(input[i]));
	}
};

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		Megaphone const megaphone;
		for (int i = 1; i < argc; ++i)
			megaphone.shout(argv[i]);
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}