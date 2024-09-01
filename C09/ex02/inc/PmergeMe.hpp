#include <vector>
#include <deque>
#include <ctime>

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
		std::vector<int>	_finalVector;
		std::vector<int>	_initialVector;
		std::deque<Pair>	_deque;
		std::vector<int> 	_jacobstahlSequence;
		bool				_isOdd;
		double				_straggler;
		int					_intCount;
		int					_pairCount;
		int					_comparisonCount;
		int					_currentFinalVectorSize;
		double				_timeSpentVector;
		double				_timeSpentDeque;

		//coplien
		PmergeMe();
		PmergeMe(const PmergeMe&);
		const PmergeMe& operator=(const PmergeMe&);
		~PmergeMe();

		// common funcs
		void	generateJacobstahlSequence();
	
		// vector
		void	vectorSort(std::vector<int> _initialVector);

		void	getInputVector(std::vector<int>& input);
		void	createFirstSortedPairing(std::vector<Pair>& _vector);
		void	sortPairsByMainChainHighestValue(std::vector<Pair>& _vector);
		void	merge(std::vector<Pair>& leftVector, std::vector<Pair>& rightVector,
				std::vector<Pair>& _vector);
		void	createFinalVector();
		void	insertPendantValuesThroughBinarySearch(std::vector<Pair>& _vector);
		void	insertValueThroughBinarySearch(int val);
		void	displayResults(std::vector<Pair>& _vector);

		// deque
		void	getInputDeque(std::vector<int>& input);
		void	createFirstSortedPairing(std::deque<Pair>& _deque);
		void	sortPairsByMainChainHighestValue(std::deque<Pair>& _deque);
		void	insertPendantValuesThroughBinarySearch(std::deque<Pair>& _deque);
		void	insertStraggler(std::deque<Pair>& _deque);
		void	displayResults(std::deque<Pair>& _deque);


		void	displayPairVector(std::vector<Pair>& input);
		void	displayIntVector(std::vector<int>& input);
		void	displayJacobstahlVector(std::vector<int>& vector);

		clock_t	startTimer();
		double	stopTimer(clock_t start);
};