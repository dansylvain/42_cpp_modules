#include <iostream>
#include "Array.hpp"
void	printB(std::string str);
void	pause();
void	print(std::string str);
template <typename T>
void	printArray(const Array<T>& array);

int main()
{
	printB("Construction with no parameter: Creates an empty array:");
	Array<int> emptyArray;
	std::cout << "Empty array size: " << emptyArray.size() << std::endl;

	pause();
	printB("Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default:");
	Array<int> intArray(5);
	printArray(intArray);

	pause();
	for (unsigned int i = 0; i < intArray.size(); ++i)
		intArray[i] = static_cast<int>(i * 10);
	printB("After putting in some values:");
	printArray(intArray);

	printB("\nUse of subscript operator [] :");
	std::cout << "value of intArray[2]: " << intArray[2] << std::endl;
	pause();
	printB("Test accessing out of bound value:");
	try
	{
		std::cout << intArray[10] << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	pause();
	printB("Test constructor bu copy");
	print("\nCreate arrayOne (size 5)");
	Array<int> arrayOne(5);
	printArray(arrayOne);
	print("\nCreate arrayTwo (copy of arrayOne)");
	Array<int>arrayTwo(arrayOne);
	printArray(arrayTwo);
	print("\nModify arrayOne content and print both arrays");
	arrayOne[0] = 21;
	arrayOne[1] = 42;
	arrayOne[2] = 666;
	arrayOne[3] = 300;
	arrayOne[4] = 2001;
	printArray(arrayOne);
	printArray(arrayTwo);
	pause();
	printB("Test assignment operator");
	arrayTwo = arrayOne;
	printArray(arrayOne);
	printArray(arrayTwo);
	
	return 0;
}

template <typename T>
void	printArray(const Array<T>& array)
{
	for (unsigned int i = 0; i < array.size(); ++i)
		std::cout << "Array[" << i << "] = " << array[i] << std::endl;
}

void	print(std::string str)
{
	std::cout << str << std::endl;
}

void	printB(std::string str)
{
	std::cout << "\033[31;1m" << str << "\033[0m" << std::endl;
}

void	pause()
{
	std::cout << std::endl;
	std::cout << "Press Enter to continue..." << std::endl;
	std::cin.get();
}
