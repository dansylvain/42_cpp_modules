#include "main.hpp"

int main() {
	Data originalData(42, "Hello World");
	uintptr_t serializedData = Serializer::serialize(&originalData);
	Data* deserializedData = Serializer::deserialize(serializedData);
	if (&originalData == deserializedData)
	{
		std::cout << "Success: The original pointer and the deserialized pointer are the same.\n";
		std::cout << "Number: " << deserializedData->number << "\n";
		std::cout << "Text: " << deserializedData->text << "\n";
	}
	else
		std::cout << "Failure: The pointers are different.\n";
	return 0;
}
