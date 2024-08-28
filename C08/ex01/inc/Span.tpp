#include <algorithm>
#include <stdexcept>

template <typename InputIterator>
void Span::addNumbers(InputIterator first, InputIterator last)
{
    size_t numToAdd = std::distance(first, last);
    if (_valuesTab.size() + numToAdd > _maxSize)
        throw std::out_of_range("Error: adding values would exceed maximum size");
    _valuesTab.insert(_valuesTab.end(), first, last);
}
