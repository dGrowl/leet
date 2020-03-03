#ifndef _SOL_1365_HPP_
#define _SOL_1365_HPP_

#include "include/helper.hpp"

class Solution {
public:
	// Time Complexity: O(N^2)
	// Memory Complexity: O(N)
	std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
		std::vector<int> smallerCount(nums.size(), 0);
		for (unsigned i = 0; i < nums.size(); ++i) {
			int number = nums[i];
			for (unsigned j = 0; j < smallerCount.size(); ++j) {
				if (nums[j] < number) {
					++smallerCount[i];
				}
			}
		}
		return smallerCount;
	}

	bool test(std::vector<int> in, std::vector<int> expected) {
		static unsigned testNumber = 1;
		Stopwatch timer;
		timer.start();
		std::vector<int> out = smallerNumbersThanCurrent(in);
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
		success &= test({8,1,2,2,3}, {4,0,1,1,3});
		success &= test({7,7,7,7}, {0,0,0,0});
		success &= test({6,5,4,8}, {2,1,0,3});
		return success;
	}
};

#endif // _SOL_1365_HPP_