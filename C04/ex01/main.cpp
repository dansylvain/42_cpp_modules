#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <ctime>
#include <cstdlib>
#include <typeinfo>

void	print(std::string str);

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));


	print("Welcome to the Jungle");
	print("");

	print("******** Animal Creation ***********");
	Animal* animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();
	print("");
	print("********** Brain Tests *************");
	for (int i = 0; i < 10; i++)
	{
		if (i == 5) print("");
		std::string str = (animals[i])->getType() + " thinks: ";
		const Dog *dogPtr = dynamic_cast<const Dog*>(animals[i]);
		const Cat *CatPtr = dynamic_cast<const Cat*>(animals[i]);
		dogPtr ? print(str + dogPtr->myBrain->getIdea()) : 
		print(str + CatPtr->myBrain->getIdea());
	}
	print("");

	print("*********** Copy Tests *************");

	const Dog *dogOne = dynamic_cast<const Dog*>(animals[4]);
	const Dog *dogTwo = dynamic_cast<const Dog*>(animals[2]);
	
	print("before assignation copy");
	print("dogOne thinks: " + dogOne->myBrain->ideas[42]);
	print("dogTwo thinks: " + dogTwo->myBrain->ideas[42]);
	print("dogOne thinks: " + dogOne->myBrain->ideas[12]);
	print("dogTwo thinks: " + dogTwo->myBrain->ideas[12]);
	print("dogOne thinks: " + dogOne->myBrain->ideas[5]);
	print("dogTwo thinks: " + dogTwo->myBrain->ideas[5]);
	print("");
	dogOne = dogTwo;
	print("after assignation copy");
	print("dogOne thinks: " + dogOne->myBrain->ideas[42]);
	print("dogTwo thinks: " + dogTwo->myBrain->ideas[42]);
	print("dogOne thinks: " + dogOne->myBrain->ideas[12]);
	print("dogTwo thinks: " + dogTwo->myBrain->ideas[12]);
	print("dogOne thinks: " + dogOne->myBrain->ideas[5]);
	print("dogTwo thinks: " + dogTwo->myBrain->ideas[5]);
	print("");

		


	print("******* Animals destruction ********");

	for (int i = 0; i < 10; i++)
		delete animals[i];
	return 0;
	(void)animals;
}

void	print(std::string str)
{
	std::cout << str << std::endl;
}



