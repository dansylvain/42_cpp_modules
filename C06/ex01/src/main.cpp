#include <iostream>
#include <stdint.h>

struct Data
{
	int number;
	std::string text;

	Data(int num, const std::string& str) : number(num), text(str) {}
};

class Serializer
{
public:
	static uintptr_t serialize(Data* ptr)
	{
		return reinterpret_cast<uintptr_t>(ptr);
	}
	static Data* deserialize(uintptr_t raw)
	{
		return reinterpret_cast<Data*>(raw);
	}

private:
	Serializer() {}
	~Serializer() {}
};

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
	{
		std::cout << "Failure: The pointers are different.\n";
	}
	return 0;
}
