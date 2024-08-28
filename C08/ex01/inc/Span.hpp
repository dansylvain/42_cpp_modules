#include <vector>

class Span
{
	private:

		std::vector<int> _valuesTab;
		unsigned long int _maxSize;

		Span();
		Span(const Span&);
		const Span& operator=(const Span&);
	public:
		Span(unsigned int N);
		~Span();

		void	addNumber(int nbr);
		int		shortestSpan() const;
		int		longestSpan() const;
};