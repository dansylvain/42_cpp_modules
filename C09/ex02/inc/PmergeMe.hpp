#include <vector>
#include <deque>

class PmergeMe
{
	private:
	public:
		std::vector<int> _vector;
		std::deque<int> _deque;

		//coplien
		PmergeMe();
		PmergeMe(const PmergeMe&);
		const PmergeMe& operator=(const PmergeMe&);
		~PmergeMe();

		// common funcs
		void	createJacobstahlSequence(const int& intCount);
	
		// vector
		void	getInputVector(std::vector<int>& input);
		void	createFirstSortedPairing(std::vector<int> input, std::vector<int>& _vector);
		void	sortPairsByMainChainHighestValue(std::vector<int>& _vector);
		void	insertPendantValuesThroughBinarySearch(std::vector<int>& _vector);
		void	insertStraggler(std::vector<int>& _vector, const int& staggler);
		void	displayResults(std::vector<int>& _vector) const;

		// deque
		void	getInputDeque(std::vector<int>& input);
		void	createFirstSortedPairing(std::vector<int> input, std::deque<int>& _vector);
		void	sortPairsByMainChainHighestValue(std::deque<int>& _vector);
		void	insertPendantValuesThroughBinarySearch(std::deque<int>& _vector);
		void	insertStraggler(std::deque<int>& _vector, const int& staggler);
		void	displayResults(std::deque<int>& _vector) const;
		
};