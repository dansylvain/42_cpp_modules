#include "EasyFind.hpp"

#include <algorithm>
#include <vector>

int main()
{
	printB("Test avec std::vector");
    std::vector<int> myVector;
    for (int i = 0; i < 10; ++i)
        myVector.push_back(i);

    try
	{
        std::vector<int>::iterator it = easyfind(myVector, 5);
        std::cout << "Element 5 found in vector at position: " << (it - myVector.begin()) << std::endl;
    }
	catch (const std::out_of_range& e)
	{
        std::cout << e.what() << std::endl;
    }

    try
	{
        std::vector<int>::iterator it = easyfind(myVector, 15);
        std::cout << "Element 15 found in vector at position: " << (it - myVector.begin()) << std::endl;
    }
	catch (const std::out_of_range& e)
	{
        std::cout << e.what() << std::endl;
    }

	printB("Test avec std::list");
    std::list<int> myList;
    for (int i = 10; i < 20; ++i)
        myList.push_back(i);

    try
	{
        std::list<int>::iterator it = easyfind(myList, 15);
        std::cout << "Element 15 found in list at position: " << std::distance(myList.begin(), it) << std::endl;
    }
	catch (const std::out_of_range& e)
	{
        std::cout << e.what() << std::endl;
    }

    try
	{
        std::list<int>::iterator it = easyfind(myList, 25);
        std::cout << "Element 25 found in list at position: " << std::distance(myList.begin(), it) << std::endl;
    }
	catch (const std::out_of_range& e)
	{
        std::cout << e.what() << std::endl;
    }

    return 0;
}