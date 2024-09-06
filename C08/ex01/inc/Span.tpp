#include <algorithm>
#include <stdexcept>

template <typename InputIterator>
void Span::addNumbers(InputIterator first, InputIterator last)
{
	size_t numToAdd = static_cast<size_t>(std::distance(first, last));
	if (_valuesTab.size() + numToAdd > _maxSize)
		throw std::out_of_range("Error: adding values would exceed maximum size");
	if (_valuesTab.size() + numToAdd == 0)
		throw std::out_of_range("Error: no values to add");
	_valuesTab.insert(_valuesTab.end(), first, last);
}
