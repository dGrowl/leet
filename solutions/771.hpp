#ifndef _LEET_SOLUTION_HPP_
#define _LEET_SOLUTION_HPP_

#include "include/helper.hpp"

class Solution {
public:
	// Time Complexity: O(MN)
	// Memory Complexity: O(1)
	// NOTE: Depending on the size of J and S, it may be worth it to 
	// put all the jewels in an unordered set for constant lookups.
	int numJewelsInStones(std::string J, std::string S) {
		int jewelCount = 0;
		for (char c: S) {
			for (char d: J) {
				if (c == d) {
					++jewelCount;
					break;
				}
			}
		}
		return jewelCount;
	}

	bool test(std::string inJ, std::string inS, int expected) {
		static unsigned testNumber = 1;
		Stopwatch timer;
		timer.start();
		int out = numJewelsInStones(inJ, inS);
		timer.stop();
		std::cout << "Test #" << testNumber++;
		if (out == expected) {
			std::cout << " PASSED [" << timer.report() << "s]" << std::endl;
			return true;
		}
		std::cout << " FAILED ["    << timer.report() << "s]" << std::endl;
		std::cout << "\tInput:    " << inJ << ", " << inS << std::endl;
		std::cout << "\tOutput:   " << out << std::endl;
		std::cout << "\tExpected: " << expected << std::endl;
		return false;
	}

	bool runTests() {
		bool success = true;
		success &= test("aA", "aAAbbbb", 3);
		success &= test("aJAEOsjlkoi", "awmeoijwaEIOJAWRIOjwarljmelkwajLKEWajFOZm", 22);
		return success;
	}
};

#endif // _LEET_SOLUTION_HPP_