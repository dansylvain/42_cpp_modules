#include "main.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	print("Cat created - with a brain");
	myBrain = new Brain();
	getGlobalKnowledge();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	type = other.getType();
	myBrain = new Brain(*other.myBrain);
	std::cout << "Dog created - with a brain" << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
	if (this == &src) return (*this);
	Animal::operator=(src);
	print("Dog copied");
	delete myBrain;
	myBrain = new Brain;
	*myBrain = *src.myBrain;
	return (*this);
}

Cat::~Cat()
{
	print("Cat destroyed");
	delete myBrain;
}

Brain *Cat::getBrain() const
{
	return (myBrain);
}

void	Cat::makeSound() const
{
	print(getType() + " says MEOW!");
}



void	Cat::getGlobalKnowledge()
{
	std::string GlobalCatKnowledge[100] =
	{
		"I am a curious explorer.",
		"I love to nap in sunny spots.",
		"I enjoy chasing laser pointers.",
		"My favorite place is high up on a perch.",
		"I am very independent.",
		"I like to play with feather toys.",
		"I enjoy lounging in cozy boxes.",
		"I am a master of purring.",
		"I love to watch birds from the window.",
		"I enjoy scratching posts.",
		"I am very graceful and agile.",
		"I like to hide in unexpected places.",
		"I enjoy being brushed.",
		"I love to play with crinkly toys.",
		"I am great at catching flies.",
		"I enjoy curling up on soft blankets.",
		"I am very observant.",
		"I like to chase shadows.",
		"I love to stretch and yawn.",
		"I am a fan of quiet naps.",
		"I enjoy climbing and jumping.",
		"I like to pounce on toys.",
		"I am very selective about my friends.",
		"I love to bat at dangling strings.",
		"I enjoy being the center of attention.",
		"I am a skilled hunter of imaginary prey.",
		"I like to explore new places in the house.",
		"I enjoy cozying up in warm places.",
		"I am a connoisseur of fine catnip.",
		"I love to sit on your lap.",
		"I enjoy batting at moving objects.",
		"I am very clean and meticulous.",
		"I like to perch on high shelves.",
		"I enjoy gentle petting and strokes.",
		"I am a master of relaxation.",
		"I love to watch the world outside.",
		"I enjoy rubbing against your legs.",
		"I am very agile and quick.",
		"I like to greet you at the door.",
		"I love to sit in boxes.",
		"I enjoy playing with shiny objects.",
		"I am very independent but love attention.",
		"I like to hide in paper bags.",
		"I love to play with string and ribbons.",
		"I enjoy watching TV with you.",
		"I am very good at catching insects.",
		"I like to nap in the laundry basket.",
		"I enjoy drinking from a running faucet.",
		"I am a fan of interactive toys.",
		"I like to scratch at furniture.",
		"I enjoy sitting on the windowsill.",
		"I am a great hunter of toy mice.",
		"I love to curl up in warm spots.",
		"I like to chase after small balls.",
		"I enjoy playing with crinkly paper.",
		"I am very curious about new things.",
		"I love to watch you work from the desk.",
		"I like to play hide and seek.",
		"I enjoy sitting in your lap.",
		"I am a fan of feather wands.",
		"I love to bat at hanging toys.",
		"I enjoy finding cozy nooks to sleep in.",
		"I am very good at climbing.",
		"I like to watch birds and squirrels outside.",
		"I enjoy being petted softly.",
		"I love to knead soft blankets.",
		"I am a great nap buddy.",
		"I like to explore new boxes and bags.",
		"I enjoy chasing after moving lights.",
		"I am very particular about my grooming.",
		"I love to sit in sunny patches.",
		"I enjoy playing with paper balls.",
		"I am very agile and quick.",
		"I like to cuddle up in warm places.",
		"I enjoy pouncing on toy mice.",
		"I am a fan of soft, plush toys.",
		"I love to watch fish in an aquarium.",
		"I enjoy finding new hiding spots.",
		"I am great at keeping you company.",
		"I like to play with interactive feeders.",
		"I enjoy watching you from high perches.",
		"I am a fan of gentle head scratches.",
		"I love to stretch and flex my claws.",
		"I enjoy napping in the sun.",
		"I am very skilled at stalking toys.",
		"I like to watch the world from the window.",
		"I enjoy finding cozy places to nap.",
		"I am very good at using my claws for climbing.",
		"I like to explore new scents.",
		"I enjoy gentle petting and brushing.",
		"I am a fan of quiet, relaxing evenings.",
		"I love to play with yarn.",
		"I enjoy sitting on the back of the couch.",
		"I am very good at keeping watch.",
		"I like to pounce on anything that moves.",
		"I enjoy playing with noisy toys.",
		"I am very particular about my sleeping spot.",
		"I love to stretch and scratch at posts.",
		"I enjoy discovering new toys.",
		"I am a master at finding hidden treats."
	};
		for (int i = 0; i < 100; i++)
			Cat::myBrain->getIdeas()[i] = GlobalCatKnowledge[std::rand() % 100];	
}