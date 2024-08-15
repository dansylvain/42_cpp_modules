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

	// pause();
	printB("\nConstruction with an unsigned int n as a parameter: Creates an array of n elements initialized by default:");
	Array<int> intArray(5);
	printArray(intArray);

	// pause();
	for (unsigned int i = 0; i < intArray.size(); ++i)
		intArray[i] = static_cast<int>(i * 10);
	printB("\nAfter putting in some values:");
	printArray(intArray);

	printB("\nUse of subscript operator [] :");
	std::cout << "value of intArray[2]: " << intArray[2] << std::endl;
	// pause();
	printB("\nTest accessing out of bound value:");
	try
	{
		std::cout << intArray[10] << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	Array<int> arrayOne(5);
	printArray(arrayOne);
	
	
	// pause();
	printB("\nTest constructor bu copy");
		print("Create arrayOne (size 5)");

		// print("Create arrayTwo (copy of arrayOne)");
		// Array<int>arrayTwo(arrayOne);
		// printArray(arrayTwo);


	return 0;
}

// template <typename T>
// void printArray(const Array<T>& array) {
//     for (unsigned int i = 0; i < array.size(); ++i) {
//         std::cout << "array[" << i << "] = " << array[i] << std::endl;
//     }
// }

template <typename T>
void	printArray(const Array<T>& array)
{
	for (unsigned int i = 0; i < array.size(); ++i)
		std::cout << "intArray[" << i << "] = " << array[i] << std::endl;
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
