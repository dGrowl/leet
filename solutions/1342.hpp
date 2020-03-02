#ifndef _SOL_1342_HPP_
#define _SOL_1342_HPP_

#include "include/helper.hpp"

class Solution {
public:
	// Time Complexity: O(logN)
	// Memory Complexity: O(1)
	int numberOfSteps(int num) {
		int steps = 0;
		while (num != 0) {
			++steps;
			if (num % 2 == 0) {
				num /= 2;
			}
			else {
				num -= 1;
			}
		}
		return steps;
	}

	bool test(int in, int expected) {
		static unsigned testNumber = 1;
		Stopwatch timer;
		timer.start();
		int out = numberOfSteps(in);
		timer.stop();
		std::cout << "Test #" << testNumber++;
		if (out == expected) {
			std::cout << " PASSED [" << timer.report() << "s]" << std::endl;
			return true;
		}
		std::cout << " FAILED ["    << timer.report() << "s]" << std::endl;
		std::cout << "\tInput:    " << in << std::endl;
		std::cout << "\tOutput:   " << numberOfSteps(in) << std::endl;
		std::cout << "\tExpected: " << expected << std::endl;
		return false;
	}

	bool runTests() {
		bool success = true;
		success &= test(14, 6);
		success &= test(8, 4);
		success &= test(123, 12);
		success &= test(52398, 24);
		return success;
	}
};

#endif // _SOL_1342_HPP_