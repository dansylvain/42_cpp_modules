#include "Span.hpp"

/**========================================================================
 *                           COPLIEN
 *========================================================================**/
Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int N)  : _maxSize(N)
{
}


Span::Span(const Span& other) : _valuesTab(other._valuesTab), _maxSize(other._maxSize)
{
}

const Span& Span::operator=(const Span& rhs)
{

	if (this != &rhs)
	{
		_valuesTab.clear();
		_valuesTab = rhs._valuesTab;
		_maxSize = rhs._maxSize;
	}
	return *this;
}

Span::~Span()
{
}

/**========================================================================
 *                           GETTERS / SETTERS
 *========================================================================**/
std::vector<int> Span::getValuesTab() const
{
	return (_valuesTab);
}

/**========================================================================
 *                           ACTION METHODS
 *========================================================================**/
void	Span::addNumber(int nbr)
{
	if (_valuesTab.size() >= _maxSize)
		throw std::overflow_error("Span full");
	_valuesTab.push_back(nbr);
}

int		Span::shortestSpan() const
{

	if (_valuesTab.size() < 2)
		throw std::logic_error("Too few elements");
		
	std::vector<int> sortedTab = _valuesTab;
	std::sort(sortedTab.begin(), sortedTab.end());

	int minSpan = std::numeric_limits<int>::max();
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
	std::vector<int>::const_iterator minIt;
	std::vector<int>::const_iterator maxIt;
	if (_valuesTab.size() < 2)
		throw std::logic_error("Too few elements");
	minIt = std::min_element(_valuesTab.begin(), _valuesTab.end());
	maxIt = std::max_element(_valuesTab.begin(), _valuesTab.end());
	return *maxIt - *minIt;
}

