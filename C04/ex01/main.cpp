#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <ctime>
#include <cstdlib>

void	print(std::string str);

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));


	print("Welcome to the Jungle");
	print("");

	print("******** Creation Tests ************");
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	print("");

	print("********** Brain Tests *************");
	const Dog* dogPtr = dynamic_cast<const Dog*>(dog);
	print(dog->getType() + " thinks: " + dogPtr->myBrain->ideas[std::rand() % 100]);
	print(dog->getType() + " thinks: " + dogPtr->myBrain->ideas[std::rand() % 100]);
	print(dog->getType() + " thinks: " + dogPtr->myBrain->ideas[std::rand() % 100]);
	print("");
	const Cat* catPtr = dynamic_cast<const Cat*>(cat);
	print(cat->getType() + " thinks: " + catPtr->myBrain->ideas[std::rand() % 100]);
	print(cat->getType() + " thinks: " + catPtr->myBrain->ideas[std::rand() % 100]);
	print(cat->getType() + " thinks: " + catPtr->myBrain->ideas[std::rand() % 100]);


	(void)dog;
	(void)cat;
	
	return 0;
}

void	print(std::string str)
{
	std::cout << str << std::endl;
}



