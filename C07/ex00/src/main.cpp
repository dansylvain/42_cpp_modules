#include "templateFunctions.hpp"

int main()
{
	{
		int x = 10, y = 20;
		std::cout << "before swap: x = " << x << ", y = " << y << std::endl;
		swap(x, y);
		std::cout << "After  swap: x = " << x << ", y = " << y << std::endl;
		
		std::cout << "Min of 10 and 20: " << min(x, y) << std::endl;
		std::cout << "Max of 10 and 20: " << max(x, y) << std::endl;
	}
	std::cout << std::endl;
	{
		double x = 15.5, y = 10.5;
		std::cout << "before swap: x = " << x << ", y = " << y << std::endl;
		swap(x, y);
		std::cout << "After  swap: x = " << x << ", y = " << y << std::endl;
		std::cout << "Min of 15.5 and 10.5: " << min(x, y) << std::endl;
		std::cout << "Max of 15.5 and 10.5: " << max(x, y) << std::endl;
	}
	return 0;
}