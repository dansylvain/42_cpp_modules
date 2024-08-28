#include "main.hpp"
#include <fstream>
void	print(std::string str)
{
	std::cout << str << std::endl;
}

void	printB(std::string str)
{
	std::cout << "\033[31;1m" << str << "\033[0m" << std::endl;
}

void	myPause()
{
	std::cout << std::endl;
	std::cout << "Press Enter to continue..." << std::endl;
	std::cin.get();
}


void saveVectorToFile(std::vector<int> tab, std::string filename)
{
	std::ofstream outFile(filename.c_str(), std::ios::out);
	if (!outFile)
	{
		std::cerr << "Error opening file: " << filename << std::endl;
		return;
	}
	for (size_t i = 0; i < tab.size(); ++i)
	{
		outFile << tab[i];
		if (i != tab.size() - 1)
			outFile << ", ";
	}
	outFile.close();
}

void printTab(std::vector<int> tab)
{
	std::cout << "Tab content:";
	
	if (tab.size() <= 10)
	{
		for (size_t i = 0; i < tab.size(); ++i) {
			std::cout << tab[i];
			if (i != tab.size() - 1) {
				std::cout << ", ";
			}
		}
	}
	else
	{
		for (size_t i = 0; i < 5; ++i)
		{
			std::cout << tab[i];
			if (i != 4)
				std::cout << ", ";
		}
		std::cout << ", [...], ";
		for (size_t i = tab.size() - 5; i < tab.size(); ++i)
		{
			std::cout << tab[i];
			if (i != tab.size() - 1)
				std::cout << ", ";
		}
		std::cout << "\033[36;1m" << "\nOpen file \"largeVector\" to see complete vector content)" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

}
