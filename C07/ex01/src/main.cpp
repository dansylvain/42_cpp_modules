#include "main.hpp"

int main()
{
	printB("Test iter with int array");
	{	
		int array[] = {1, 2, 3, 4, 5};
		unsigned int len = sizeof(array) / sizeof(array[0]);
		iter(array, len, print);
	}
	pause();
	printB("Test iter with char array");
	{	
		char array[] = {'a', 'b', 'c', 'd', 'e'};
		unsigned int len = sizeof(array) / sizeof(array[0]);
		iter(array, len, print);
	}
	pause();
	printB("Test iter with std::string array");
	{	
		std::string array[] = {"Welcome", "to", "the", "jungle"};
		unsigned int len = sizeof(array) / sizeof(array[0]);
		iter(array, len, print);
	}
	return 0;
}