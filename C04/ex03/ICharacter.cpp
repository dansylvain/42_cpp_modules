#include "ICharacter.hpp"
#include "Character.hpp"

ICharacter	*ICharacter::characters[100] = {NULL};
int			ICharacter::characterCount = 0;

void	ICharacter::createNewCharacter(const std::string &name)
{
	if (characterCount < 100) {
        characters[characterCount++] = new Character(name);
    }
printB("CREATE NEW CHARACTER " + name + " !!!");	
}

void	ICharacter::cleanup()
{
	for (int i = 0; i < ICharacter::characterCount; ++i) {
		print("*************deleting**************");
        delete characters[i];
    }

	for (int i = 0; i < 100; ++i) {
        characters[i] = NULL;
    }
    characterCount = 0;
}
