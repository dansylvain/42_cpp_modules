#include "ICharacter.hpp"
#include "Character.hpp"

ICharacter	*ICharacter::characters[100] = {NULL};
int			ICharacter::characterCount = 0;

ICharacter*	ICharacter::createNewCharacter(const std::string &name)
{
	Character* ptr;
	ptr = new Character(name);
	if (characterCount < 100)
	{
        characters[characterCount++] = ptr;
    }
	print("new ICharacter created");
	return (ptr);
}

void	ICharacter::cleanup()
{
	for (int i = 0; i < ICharacter::characterCount; ++i) {
        delete characters[i];
    }

	for (int i = 0; i < 100; ++i) {
        characters[i] = NULL;
    }
    characterCount = 0;
}
