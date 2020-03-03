#ifndef _LEET_SOLUTION_HPP_
#define _LEET_SOLUTION_HPP_

#include "include/helper.hpp"

class Solution {
public:
	// Time Complexity: O(N)
	// Memory Complexity: O(1)
	int subtractProductAndSum(int n) {
		unsigned sum = 0;
		unsigned product = 1;
		while (n != 0) {
			int digit = n % 10;
			sum += digit;
			product *= digit;
			n /= 10;
		}
		return (product - sum);
	}

	bool test(int in, int expected) {
		static unsigned testNumber = 1;
		Stopwatch timer;
		timer.start();
		int out = subtractProductAndSum(in);
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
		success &= test(234, 15);
		success &= test(4421, 21);
		success &= test(98234, 1702);
		success &= test(99999, 59004);
		success &= test(34845, 1896);
		success &= test(3333, 69);
		success &= test(1, 0);
		success &= test(2, 0);
		success &= test(45, 11);
		success &= test(237, 30);
		return success;
	}
};

#endif // _LEET_SOLUTION_HPP_