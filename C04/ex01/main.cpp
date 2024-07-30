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
const Animal* meta = new Animal();
const Animal* dog = new Dog();
const Animal* cat = new Cat();
const WrongAnimal* wa = new WrongAnimal();
const WrongAnimal* wc = new WrongCat();
print("");

print("********Makesound Test ************");
meta->makeSound();
cat->makeSound();
dog->makeSound();
wa->makeSound();
wc->makeSound();
print("");



print("*****Copy constructor Test ********");
Dog CopyDog(*dynamic_cast<const Dog*>(dog));
CopyDog.makeSound();
print(CopyDog.getType());
print("");

WrongCat CopyCat(*dynamic_cast<const WrongCat*>(wc));
CopyCat.makeSound();
print(CopyCat.getType());
print("");

/**========================================================================
 * ? class cannot be assigned at random.
 * ? only "compatible" classes can be assigned
 * ? hence, I did it on the stack, not to loose reference
 *========================================================================**/

print("*****assign. operator Test ********");

const Animal* animalPtr = &CopyDog;
print("Before Transgender Surgery:");
animalPtr->makeSound();
animalPtr = cat;
print("After Transgender Surgery:");
animalPtr->makeSound();
print("");

const WrongAnimal* WanimalPtr = &CopyCat;
print("Before Transgender Surgery:");
WanimalPtr->makeSound();
WanimalPtr = wc;
print("After Transgender Surgery:");
WanimalPtr->makeSound();
print("");

delete meta;
delete cat;
delete dog;
delete wa;
delete wc;

}

void	print(std::string str)
{
	std::cout << str << std::endl;
}