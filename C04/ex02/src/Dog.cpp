#include "main.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
Dog::Dog() : AAnimal()
{
	type = "Dog";
	print("Dog created (default constructor)");
	myBrain = new Brain();
	getGlobalKnowledge();
}

Dog::Dog(const Dog &src) : AAnimal(src)
{
	type = src.getType();
	myBrain = new Brain(src.myBrain);
	std::cout << "Dog created (copy constructor)" << std::endl;
}

Dog::~Dog()
{
	print("Dog destroyed");
	delete myBrain;
}

/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
Dog& Dog::operator=(const Dog& other)
{
	if (this == &other) return (*this);
	print("Dog copied");
	*myBrain = *other.myBrain;
	return (*this);
}

/**========================================================================
 *                           OTHER METHODS
 *========================================================================**/
void	Dog::makeSound() const
{
	print(getType() + " says WOOF!");
}

/**========================================================================
 *                           GETTERS AND SETTERS>
 *========================================================================**/
Brain *Dog::getBrain() const
{
	return (myBrain);
}

void	Dog::getGlobalKnowledge()
{
	std::string GlobalDogKnowledge[100] =
	{
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
		"I love to receive lots of affection and praise."
		};
		for (int i = 0; i < 100; i++)
			Dog::myBrain->getIdeas()[i] = GlobalDogKnowledge[std::rand() % 100];
}