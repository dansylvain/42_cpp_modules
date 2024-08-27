#include "main.hpp"

Base* generate(void)
{
	int random = rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

std::string identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		return "A";
	else if (dynamic_cast<B*>(p))
		return "B";
	else if (dynamic_cast<C*>(p))
		return "C";
	else
		return "Unknown type";
}

void identify(Base& p)
{
	try 
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (const std::exception & e) {};
	try 
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (const std::exception & e) {};
	try 
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (const std::exception & e) {};

}

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	for (int i = 0; i < 5; i++)
	{
		Base* obj = generate();
		std::cout << "Identify by pointer: " << identify(obj) << std::endl;
		std::cout << "Identify by reference: " << std::flush; identify(*obj);
		delete obj;
		std::cout << std::endl;
	}
	return (0);
}