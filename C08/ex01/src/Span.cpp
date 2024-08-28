#include "Span.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <limits>
Span::Span(unsigned int N) : _maxSize(N)
{
}

Span::~Span()
{
}


void	Span::addNumber(int nbr)
{
	if (_valuesTab.size() >= _maxSize)
		throw std::overflow_error("Span full");
	_valuesTab.push_back(nbr);
}

int		Span::shortestSpan() const
{
	int minSpan = std::numeric_limits<int>::max();

	if (_valuesTab.size() < 2)
		throw std::logic_error("Too few elements");
	std::vector<int> sortedTab = _valuesTab;
	std::sort(sortedTab.begin(), sortedTab.end());

	for (long unsigned int i = 1; i < sortedTab.size(); i++)
	{
		int span = sortedTab[i] - sortedTab[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int		Span::longestSpan() const
{
	if (_valuesTab.size() < 2)
		throw std::logic_error("Too few elements");
	return 42;
}
