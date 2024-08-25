#include <iostream>
#include <stdint.h>

struct Data;

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer&);
		const Serializer& operator=(const Serializer&);
};
