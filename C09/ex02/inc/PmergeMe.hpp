#include <vector>
#include <deque>

class PmergeMe
{
	private:
	public:


		typedef struct pair
		{
			int main;
			int pendant;
		} Pair;

		std::vector<pair>	_vector;
		std::deque<Pair>	_deque;
		std::vector<int> 	_jacobstahlSequence;
		bool				_isOdd;
		double				_straggler;
		int					_intCount;
		int					_pairCount;

		//coplien
		PmergeMe();
		PmergeMe(const PmergeMe&);
		const PmergeMe& operator=(const PmergeMe&);
		~PmergeMe();

		// common funcs
		void	generateJacobstahlSequence();
	
		// vector
		void	getInputVector(std::vector<int>& input);
		void	createFirstSortedPairing(std::vector<Pair>& _vector);
		void	sortPairsByMainChainHighestValue(std::vector<Pair>& _vector);
		void	insertPendantValuesThroughBinarySearch(std::vector<Pair>& _vector);
		void	insertStraggler(std::vector<Pair>& _vector);
		void	displayResults(std::vector<Pair>& _vector) const;

		// deque
		void	getInputDeque(std::vector<int>& input);
		void	createFirstSortedPairing(std::deque<Pair>& _deque);
		void	sortPairsByMainChainHighestValue(std::deque<Pair>& _deque);
		void	insertPendantValuesThroughBinarySearch(std::deque<Pair>& _deque);
		void	insertStraggler(std::deque<Pair>& _deque);
		void	displayResults(std::deque<Pair>& _deque) const;


		void	displayVector(std::vector<Pair>& input);

};