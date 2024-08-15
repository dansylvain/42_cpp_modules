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
meta->makeSound();
cat->makeSound();
dog->makeSound();
wa->makeSound();
wc->makeSound();
print("");



pause();
printB("*****Copy constructor Test ********");
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

pause();
printB("*****assign. operator Test ********");
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

pause();
printB("****** cleaning ressources ********");
delete meta;
delete cat;
delete dog;
delete wa;
delete wc;

}