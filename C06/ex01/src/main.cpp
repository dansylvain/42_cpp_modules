#include <iostream>
#include <stdint.h> // Pour uintptr_t

// Définition de la structure Data
struct Data {
    int number;
    std::string text;

    Data(int num, const std::string& str) : number(num), text(str) {}
};

// Définition de la classe Serializer
class Serializer {
public:
    static uintptr_t serialize(Data* ptr){
        return reinterpret_cast<uintptr_t>(ptr);
    }

    static Data* deserialize(uintptr_t raw) {
        return reinterpret_cast<Data*>(raw);
    }

private:
    // Pour éviter que la classe soit instanciée
    Serializer() {}
    ~Serializer() {}
};

int main() {
    // Création d'un objet Data
    Data originalData(42, "Hello World");

    // Sérialisation de l'objet
    uintptr_t serializedData = Serializer::serialize(&originalData);

    // Désérialisation de l'objet
    Data* deserializedData = Serializer::deserialize(serializedData);

    // Vérification que les données ont été correctement désérialisées
    if (&originalData == deserializedData) {
        std::cout << "Success: The original pointer and the deserialized pointer are the same.\n";
        std::cout << "Number: " << deserializedData->number << "\n";
        std::cout << "Text: " << deserializedData->text << "\n";
    } else {
        std::cout << "Failure: The pointers are different.\n";
    }

    return 0;
}
