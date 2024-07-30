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
const Animal* j = new Dog();
const Animal* i = new Cat();

print("");

meta->makeSound();
i->makeSound();
j->makeSound();
print("");

const WrongAnimal* wa = new WrongAnimal();
const WrongAnimal* wc = new WrongCat();
print("");

wa->makeSound();
wc->makeSound();
print("");


delete meta;
delete i;
delete j;

}

void	print(std::string str)
{
	std::cout << str << std::endl;
}