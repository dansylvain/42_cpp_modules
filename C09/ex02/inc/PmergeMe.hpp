#include <vector>
#include <deque>

class PmergeMe
{
	private:
	public:
		std::vector<int> _vector;
		std::deque<int> _deque;
		void	validateInput(const int* input) const;
		void	createJacobstahlSequence(const int& intCount);
	
		void	createFirstSortedPairing(int* input, std::vector<int>& _vector);
		void	sortPairsByMainChainHighestValue(std::vector<int>& _vector);
		void	insertPendantValuesThroughBinarySearch(std::vector<int>& _vector);
		void	insertStraggler(std::vector<int>& _vector, const int& staggler);
		void	displayResults(std::vector<int>& _vector) const;

		void	createFirstSortedPairing(int* input, std::deque<int>& _vector);
		void	sortPairsByMainChainHighestValue(std::deque<int>& _vector);
		void	insertPendantValuesThroughBinarySearch(std::deque<int>& _vector);
		void	insertStraggler(std::deque<int>& _vector, const int& staggler);
		void	displayResults(std::deque<int>& _vector) const;
		
};