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

print("*****Copy constructor Test ********");
const Animal *CopyDog = new Dog(*dynamic_cast<const Dog*>(dog));
CopyDog->makeSound();
print(CopyDog->getType());
print("");

const WrongAnimal *CopyWCat = new WrongCat(*dynamic_cast<const WrongCat*>(wc));
CopyWCat->makeSound();
print(CopyWCat->getType());
print("");

print("*****assign. operator Test ********");

print("Before Transgender Surgery:");
CopyDog->makeSound();
CopyDog = cat;
print("After Transgender Surgery:");
CopyDog->makeSound();
print("");


print("********Makesound Test ************");
meta->makeSound();
cat->makeSound();
dog->makeSound();
wa->makeSound();
wc->makeSound();
print("");








print("");


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