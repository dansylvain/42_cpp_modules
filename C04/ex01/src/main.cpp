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
	print("**** Copy constructor test *********");
	const Cat *catPtr = dynamic_cast<Cat*>(animals[8]);
	print("PussyCat thinks: " + catPtr->myBrain->ideas[7]);
	print("PussyCat thinks: " + catPtr->myBrain->ideas[15]);
	print("PussyCat thinks: " + catPtr->myBrain->ideas[42]);

	print("");
	Cat copyCat(*catPtr);
	print("");

	print("Pussy thinks:   " + catPtr->myBrain->ideas[7]);
	print("copyCat thinks: " + copyCat.myBrain->ideas[7]);
	print("Pussy thinks:   " + catPtr->myBrain->ideas[15]);
	print("copyCat thinks: " + copyCat.myBrain->ideas[15]);
	print("Pussy thinks:   " + catPtr->myBrain->ideas[42]);
	print("copyCat thinks: " + copyCat.myBrain->ideas[42]);


	print("");
	print("***** Assignment Tests *************");
	Dog *dogOne = dynamic_cast<Dog*>(animals[4]);
	Dog *dogTwo = dynamic_cast<Dog*>(animals[2]);
	
	print("before assignment");
	print("dogOne thinks: " + dogOne->myBrain->ideas[42]);
	print("dogTwo thinks: " + dogTwo->myBrain->ideas[42]);
	print("dogOne thinks: " + dogOne->myBrain->ideas[12]);
	print("dogTwo thinks: " + dogTwo->myBrain->ideas[12]);
	print("dogOne thinks: " + dogOne->myBrain->ideas[5]);
	print("dogTwo thinks: " + dogTwo->myBrain->ideas[5]);
	print("");

	*dogOne = *dogTwo;

	print("");
	print("after assignment");
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



