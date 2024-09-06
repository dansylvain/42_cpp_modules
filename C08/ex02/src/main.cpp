#include "MutantStack.hpp"
#include <list>
#include <vector>
#include <string>
#include <iostream>
#include "main.hpp"

int main()
{
	//! *******************************************************
	//?  				SUBJECT'S TEST
	//! *******************************************************
	printB("Subjects's test:\nMutantStack:");
	{
		MutantStack<int>mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
			std::cout << *it++ << std::endl;
		std::stack<int> s(mstack);
	}
	printB("std::list:");
	{
		std::list<int> mlist;
		mlist.push_back(5);
		mlist.push_back(17);
		std::cout << mlist.back() << std::endl;
		mlist.pop_back();
		std::cout << mlist.size() << std::endl;
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);
		//[...]
		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();
		while (it != ite)
			std::cout << *it++ << std::endl;
		std::stack<int, std::list<int> > s(mlist);
	}

	//! *******************************************************
	//?  				TEST WITH STRINGS
	//! *******************************************************
	myPause();
	{
		printB("Test with strings");
		MutantStack<std::string> mstack;
		mstack.push("Hello");
		mstack.push("World");
		std::cout << "Top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size after pop: " << mstack.size() << std::endl;
		mstack.push("Foo");
		mstack.push("Bar");
		mstack.push("Baz");
		MutantStack<std::string>::iterator it = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end();
		while (it != ite)
			std::cout << *it++ << std::endl;
	}

	//! *******************************************************
	//?  				TEST OF CONST ITERATOR
	//! *******************************************************
	myPause();
	{
		printB("Test const iterator:");
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		MutantStack<int>::const_iterator it = mstack.begin();
		MutantStack<int>::const_iterator ite = mstack.end();
		while (it != ite)
			std::cout << *it++ << std::endl;
	}
	//! *******************************************************
	//?  				TEST EMPTY PILE
	//! *******************************************************
	myPause();
	{
		printB("Test empty pile");
		MutantStack<int> emptyStack;
		std::cout << "Is stack empty? " << (emptyStack.empty() ? "Yes" : "No") << std::endl;
		std::cout << "Attempting to access top element of empty stack:" << std::endl;
		if (emptyStack.empty())
			std::cerr << "Cannot access top element: Stack is empty." << std::endl;
		else
			std::cout << emptyStack.top() << std::endl;
	}

	//! *******************************************************
	//?  				TEST DIFFERENT TYPES
	//! *******************************************************
	myPause();
	{
		printB("Test different types");
		MutantStack<double> doubleStack;
		doubleStack.push(3.1415);
		doubleStack.push(2.7182);
		doubleStack.push(1.2345);
		doubleStack.push(7.2340);
		std::cout << "Top of double stack: " << doubleStack.top() << std::endl;
		MutantStack<std::string> stringStack;
		stringStack.push("Hello");
		stringStack.push("World");
		stringStack.push("I Love Pinapple");
		std::cout << "Top of string stack: " << stringStack.top() << std::endl;
		MutantStack<std::vector<int> > vectorStack;
		vectorStack.push(std::vector<int>(3, 42));
		std::cout << "Top of vector stack (size of vector): " << vectorStack.top().size() << std::endl;
	}

	//! *******************************************************
	//?  				TEST COPY CONSTRUCTOR
	//! *******************************************************
	myPause();
	{
		printB("Test copy constructor and assignation operator");
		MutantStack<int> originalStack;
		for (int i = 0; i < 5; ++i)
			originalStack.push(i);
		// test assignment operator
		MutantStack<int> copiedStack(originalStack);
		std::cout << "Original stack size: " << originalStack.size() << std::endl;
		std::cout << "Copied stack size: " << copiedStack.size() << std::endl;
		// modify original stack
		originalStack.push(100);
		std::cout << "Original stack top after modification: " << originalStack.top() << std::endl;
		std::cout << "Copied stack top after original modification: " << copiedStack.top() << std::endl;
		// test assignment operator
		MutantStack<int> assignedStack;
		assignedStack = originalStack;
		std::cout << "Assigned stack size: " << assignedStack.size() << std::endl;
		std::cout << "Assigned stack top: " << assignedStack.top() << std::endl;
	}

	//! *******************************************************
	//?  				TEST ITERATORS
	//! *******************************************************
	myPause();
	{
		printB("Test des itérateurs const");
		MutantStack<int> mstack;
		mstack.push(10);
		mstack.push(20);
		mstack.push(30);
		MutantStack<int>::const_iterator it = mstack.begin();
		MutantStack<int>::const_iterator ite = mstack.end();
		std::cout << "Iterating through MutantStack with const iterator:" << std::endl;
		while (it != ite)
			std::cout << *it++ << std::endl;
		//? Uncomment to generate compilation error
		// *it = 42; // Cannot modify through a const_iterator
	}

	//! *******************************************************
	//?  				TEST LARGE AMOUNT OF NUMBERS
	//! *******************************************************
	myPause();
	{
		printB("Test large amount of data");
		MutantStack<int> largeStack;
		for (int i = 0; i < 10000; ++i)
			largeStack.push(i);
		std::cout << "Size of large stack: " << largeStack.size() << std::endl;
		MutantStack<int>::iterator it = largeStack.begin();
		MutantStack<int>::iterator ite = largeStack.end();
		std::cout << "Iterating through first 10 elements of large stack:" << std::endl;
		for (int i = 0; i < 10 && it != ite; ++i)
			std::cout << *it++ << std::endl;
	}
	return 0;
}
