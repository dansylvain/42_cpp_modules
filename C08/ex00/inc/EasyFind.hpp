#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>

template <typename Container>
typename Container::iterator easyfind(Container& container, int n)
{
    typename Container::iterator it;
    it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::out_of_range("Element not found");
    return it;
}

void	print(std::string str);
void	printB(std::string str);
void	pause();