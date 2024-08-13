#include <iostream>
#include "Array.hpp"

int main() {
    // Crée un tableau de 5 entiers
    Array<int> intArray(5);

    for (size_t i = 0; i < intArray.getSize(); ++i) {
        intArray[i] = static_cast<int>(i * 2); // Initialiser les éléments
    }

    std::cout << "Integer array:" << std::endl;
    for (size_t i = 0; i < intArray.getSize(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // Crée un tableau de 3 chaînes de caractères
    Array<std::string> stringArray(3);

    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "C++";

    std::cout << "String array:" << std::endl;
    for (size_t i = 0; i < stringArray.getSize(); ++i) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
