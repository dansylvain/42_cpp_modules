#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <limits>

class Span
{
	private:

		std::vector<int> _valuesTab;
		unsigned long int _maxSize;

	public:
		Span();
		Span(const Span&);
		const Span& operator=(const Span&);
		Span(unsigned int N);
		~Span();

		std::vector<int> getValuesTab() const;
		void	addNumber(int nbr);
		template <typename InputIterator>
        void addNumbers(InputIterator first, InputIterator last);
		int		shortestSpan() const;
		int		longestSpan() const;
};

#include "Span.tpp"