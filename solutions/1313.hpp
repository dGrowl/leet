#ifndef _SOL_1108_HPP_
#define _SOL_1108_HPP_

#include "include/helper.hpp"

class Solution {
public:
	// Time Complexity: O(M+N)
	// Memory Complexity: O(M+N)
	std::vector<int> decompressRLElist(std::vector<int>& nums) {
		std::vector<int> decompressed;
		for (unsigned i = 0; i < nums.size(); i += 2) {
			unsigned length = nums[i];
			for (unsigned int j = 0; j < length; ++j) {
				int value = nums[i + 1];
				decompressed.push_back(value);
			}
		}
		return decompressed;
	}

	bool test(std::vector<int> in, std::vector<int> expected) {
		static unsigned testNumber = 1;
		Stopwatch timer;
		timer.start();
		std::vector<int> out = decompressRLElist(in);
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
		success &= test({1,2,3,4}, {2,4,4,4});
		success &= test({1,2,3,6,7,22,4,55,1,3,7,13,65,2,44,6,2,2,45,4,9,76,3,4}, {2,6,6,6,22,22,22,22,22,22,22,55,55,55,55,3,13,13,13,13,13,13,13,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,2,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,76,76,76,76,76,76,76,76,76,4,4,4});
		return success;
	}
};

#endif // _SOL_1108_HPP_