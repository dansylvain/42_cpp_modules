#include "main.hpp"

int main()
{
	printB("Welcome to the Jungle");
	print("");

	printB("******** Creation Tests ************");
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();
	print("");

	pause();
	printB("********Makesound Test ************");
	std::cout<< meta->getType() << std::flush; meta->makeSound();
	std::cout<< cat->getType() << std::flush; cat->makeSound();
	std::cout<< dog->getType() << std::flush; dog->makeSound();
	std::cout<< wa->getType() << std::flush; wa->makeSound();
	std::cout<< wc->getType() << std::flush; wc->makeSound();
	print("");



	pause();
	printB("*****Copy constructor Test ********");
	Dog CopyDog(*dynamic_cast<const Dog*>(dog));
	std::cout << CopyDog.getType() << std::flush; CopyDog.makeSound();
	print("");

	WrongAnimal CopyCat(*dynamic_cast<const WrongCat*>(wc));
	std::cout << CopyCat.getType() << std::flush; CopyCat.makeSound();
	print("");

	WrongCat CopyCat2(*dynamic_cast<const WrongCat*>(wc));
	std::cout << CopyCat2.getType() << std::flush; CopyCat2.makeSound();
	print("");

	/**========================================================================
	 * ? class cannot be assigned at random.
	 * ? only "compatible" classes can be assigned without explicit casting
	 * ? hence, I did it on the stack, not to loose reference
	 *========================================================================**/

	pause();
	printB("*****assign. operator Test ********");
	const Animal* animalPtr = &CopyDog;
	print("Before Transgender Surgery:");
	std::cout << animalPtr->getType(); animalPtr->makeSound();
	animalPtr = cat;
	print("After Transgender Surgery:");
	std::cout << animalPtr->getType(); animalPtr->makeSound();
	print("");

	const WrongAnimal* WanimalPtr = &CopyCat;
	print("Before Transgender Surgery:");
	std::cout << WanimalPtr->getType(); WanimalPtr->makeSound();
	WanimalPtr = wc;
	print("After Transgender Surgery:");
	std::cout << WanimalPtr->getType(); WanimalPtr->makeSound();
	print("");

	pause();
	printB("****** cleaning ressources ********");
	delete meta;
	delete cat;
	delete dog;
	delete wa;
	delete wc;
}