

#include "Span.hpp"
#include "main.hpp"
#include <iostream>
#include <vector>
#include <cstdlib> // Pour std::rand et std::srand
#include <ctime>   // Pour std::time
#include <stdexcept> // Pour std::exception, std::logic_error, std::overflow_error

int main(void)
{
	//! *******************************************************
	//?  				SUBJECT'S TEST
	//! *******************************************************
	printB("Subject's test:");
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	myPause();
	printB("Create Span size max  == 10 and add 10 numbers (using method addNumber)" );
	Span sp(10);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(9);
	sp.addNumber(1);
	sp.addNumber(7);
	sp.addNumber(2);
	sp.addNumber(6);
	sp.addNumber(8);
	sp.addNumber(4);
	sp.addNumber(0);
	printTab(sp.getValuesTab());
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	myPause();
	printB("Create Span size max  == 20000 and add 20000 random numbers (using method addNumber)" );
	Span spLarge(20000);
	std::srand(static_cast<unsigned int>(std::time(0)));
	for (unsigned long int i = 0; i < 20000; ++i) {
		spLarge.addNumber(std::rand() % 20000);
	}
	printTab(spLarge.getValuesTab());
	saveVectorToFile(spLarge.getValuesTab(), "largeVector");
	
	std::cout << "Shortest span in large Span: " << spLarge.shortestSpan() << std::endl;
	std::cout << "Longest span in large Span: " << spLarge.longestSpan() << std::endl;

	//! *******************************************************
	//?  				TEST EXCEPTIONS
	//! *******************************************************
	myPause();
	printB("\nTest exceptions:");
	Span spSmall(2);
	spSmall.addNumber(10);
	spSmall.addNumber(20);
	try
	{
		spSmall.addNumber(30);
	}
	catch (const std::overflow_error& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Span spEmpty(1);
		spEmpty.addNumber(5);
		std::cout << "Shortest span in empty Span: " << spEmpty.shortestSpan() << std::endl;
	}
	catch (const std::logic_error& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Span spSingle(1);
		spSingle.addNumber(1);
		std::cout << "Shortest span in single element Span: " << spSingle.shortestSpan() << std::endl;
	}
	catch (const std::logic_error& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	//! *******************************************************
	//?  				TEST METHOD ADDNUMBERS
	//! *******************************************************
	myPause();
	printB("Test method addNumbers:");
	try
	{
		Span sp(20);
		std::vector<int> data;
		for (int i = 1; i <= 10; ++i)
			data.push_back(i);
		sp.addNumbers(data.begin(), data.end());
		std::cout << "Test 1: ";
		printTab(sp.getValuesTab());
	}
	catch (const std::exception &e)
	{
		std::cerr << "Test 2: " << e.what() << std::endl;
	}
	try
	{
		Span sp(10);
		std::vector<int> data;
		for (int i = 1; i <= 10; ++i)
			data.push_back(i);
		sp.addNumbers(data.begin(), data.end());
		std::vector<int> moreData;
		for (int i = 11; i <= 13; ++i)
			moreData.push_back(i);
		sp.addNumbers(moreData.begin(), moreData.end());
		std::cout << "Test 2: ";
		printTab(sp.getValuesTab());
	}
	catch (const std::exception &e)
	{
		std::cerr << "Test 2: " << e.what() << std::endl;
	}
	try
	{
		Span sp(15);
		std::vector<int> data;
		for (int i = 1; i <= 15; ++i)
			data.push_back(i);
		sp.addNumbers(data.begin(), data.begin() + 10);
		sp.addNumber(16);
		sp.addNumber(17);
		std::cout << "Test 3: ";
		printTab(sp.getValuesTab());
		saveVectorToFile(sp.getValuesTab(), "smallVector");
	}
	catch (const std::exception &e)
	{
		std::cerr << "Test 3: " << e.what() << std::endl;
	}
	try
	{
		Span sp(10);
		std::vector<int> data;
		sp.addNumbers(data.begin(), data.end());
		std::cout << "Test 4: ";
		printTab(sp.getValuesTab());
	}
	catch (const std::exception &e)
	{
		std::cerr << "Test 4: " << e.what() << std::endl;
	}
	

	return 0;
}
