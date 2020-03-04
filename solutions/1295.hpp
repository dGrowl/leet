#ifndef _LEET_SOLUTION_HPP_
#define _LEET_SOLUTION_HPP_

#include "include/helper.hpp"

class Solution {
public:
	// Time Complexity: O(N)
	// Memory Complexity: O(1)
	unsigned hasEvenNumberOfDigits(int n) {
		if (n < 10) return 0;
		if (n < 100) return 1;
		if (n < 1000) return 0;
		if (n < 10000) return 1;
		if (n < 100000) return 0;
		return 1;
	}

	int findNumbers(std::vector<int>& nums) {
		unsigned evensCount = 0;
		for (int i: nums) {
			evensCount += hasEvenNumberOfDigits(i);
		}
		return evensCount;
	}

	bool test(std::vector<int> in, int expected) {
		static unsigned testNumber = 1;
		Stopwatch timer;
		timer.start();
		int out = findNumbers(in);
		timer.stop();
		std::cout << "Test #" << testNumber++;
		if (out == expected) {
			std::cout << " PASSED [" << timer.report() << "s]" << std::endl;
			return true;
		}
		std::cout << " FAILED ["    << timer.report() << "s]" << std::endl;
		std::cout << "\tInput:    " << in << std::endl;
		std::cout << "\tOutput:   " << out << std::endl;
		std::cout << "\tExpected: " << expected << std::endl;
		return false;
	}

	bool runTests() {
		bool success = true;
		success &= test({12,345,2,6,7896}, 2);
		success &= test({12,3,485,283,5432,431,543,6574,431,1,23,5,3,6,43,7,46,65,786,67667,100000,69459,2138,5343}, 10);
		return success;
	}
};

#endif // _LEET_SOLUTION_HPP_