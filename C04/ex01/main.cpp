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


void	getGlobalDogKnowledge() {
	std::string GlobalDogKnowledge[100] = {
		"I am a loyal companion.",
		"I love chasing balls.",
		"My favorite treat is a chew toy.",
		"I enjoy long walks in the park.",
		"I am always excited to see you.",
		"I love belly rubs.",
		"I am a natural fetch player.",
		"I like to dig in the yard.",
		"I am very protective of my family.",
		"I enjoy playing with other dogs.",
		"I have a big appetite.",
		"I love car rides.",
		"I am a great watchdog.",
		"I enjoy snuggling on the couch.",
		"I am curious and like to explore.",
		"I love to roll in the grass.",
		"I am always up for a game of tug-of-war.",
		"I enjoy learning new tricks.",
		"I am a playful and energetic pup.",
		"I like to run around in the backyard.",
		"I am good at sniffing out treats.",
		"I love to play in the water.",
		"I am a faithful and obedient friend.",
		"I enjoy visiting the dog park.",
		"I love to chase after squirrels.",
		"I am a big fan of treats and snacks.",
		"I enjoy getting my fur brushed.",
		"I like to cuddle with you at night.",
		"I am very social and friendly.",
		"I love to play hide and seek.",
		"I enjoy lying in the sun.",
		"I am always happy to see you come home.",
		"I love rolling around in the leaves.",
		"I am great at guarding the house.",
		"I enjoy playing with squeaky toys.",
		"I am a champion at jumping for frisbees.",
		"I like to follow you everywhere.",
		"I love to run and play in the park.",
		"I am a fan of training sessions.",
		"I enjoy chasing my tail.",
		"I am very affectionate and loving.",
		"I love to explore new scents.",
		"I am a great jogging partner.",
		"I enjoy chewing on bones.",
		"I am very playful with children.",
		"I like to nap in the sun.",
		"I am always excited for meal times.",
		"I love to dig in the sand.",
		"I am a loyal and steadfast friend.",
		"I enjoy playing with interactive toys.",
		"I like to watch the world go by from the window.",
		"I love to cuddle in a warm blanket.",
		"I enjoy meeting new people.",
		"I am a fan of adventure and hiking.",
		"I love to chase bubbles.",
		"I enjoy playing with other animals.",
		"I like to dig up hidden treasures in the yard.",
		"I am always eager to learn new commands.",
		"I love to play with colorful toys.",
		"I enjoy napping next to you.",
		"I am great at fetching sticks.",
		"I like to roll on my back and wiggle.",
		"I love to explore new parks and trails.",
		"I enjoy the thrill of running off-leash.",
		"I am very good at following scents.",
		"I like to be involved in family activities.",
		"I love to get my paws wet in puddles.",
		"I enjoy relaxing after a long play session.",
		"I am very good at comforting you when you are sad.",
		"I like to play with squeaky balls.",
		"I enjoy sniffing out new smells on walks.",
		"I am very affectionate and love attention.",
		"I like to be the center of attention.",
		"I enjoy playing hide-and-seek with you.",
		"I love to play in the snow.",
		"I enjoy the excitement of chasing a ball.",
		"I am great at learning new tricks.",
		"I like to follow you around the house.",
		"I love to sit by the fireplace.",
		"I enjoy chewing on different textures.",
		"I am a great partner for outdoor adventures.",
		"I like to snuggle up on cold days.",
		"I enjoy getting dirty and then rolling in the grass.",
		"I am always up for a game of catch.",
		"I love to explore new environments.",
		"I enjoy lying in the sun and soaking up the warmth.",
		"I am very loyal and protective of my family.",
		"I like to play with toys that make noise.",
		"I love to play in the rain.",
		"I enjoy getting belly rubs after a long day.",
		"I am a fan of puzzle toys that challenge me.",
		"I like to nap next to you on the couch.",
		"I love to chase after frisbees in the park.",
		"I enjoy finding hidden treats.",
		"I am very enthusiastic about meal times.",
		"I like to be a part of family outings.",
		"I love to play with water from the hose.",
		"I enjoy playing tug-of-war with my favorite rope.",
		"I am a fan of soft, cozy beds.",
		"I love to receive lots of affection and praise."};
}

void	getGlobalCatKnowledge() {
	std::string GlobalCatKnowledge[100] = {
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
	
	}