#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void	print(std::string str);

int main()
{
	print("Welcome to the Jungle");
	print("");

	print("******** Creation Tests ************");
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	print("");

	(void)dog;
	(void)cat;
}

void	print(std::string str)
{
	std::cout << str << std::endl;
}



