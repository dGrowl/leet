#ifndef _SOL_1108_HPP_
#define _SOL_1108_HPP_

#include "include/helper.hpp"

class Solution {
public:
	// Time Complexity: O(N)
	// Memory Complexity: O(1)
	std::string defangIPaddr(std::string address) {
		address.reserve(address.size() + 6);
		for (unsigned i = 1; i < address.size(); ++i) { // Valid IPv4 address will begin with a digit
			if (address[i] == '.') {
				address.replace(i, 1, "[.]");
				i += 3; // skip over .]#
			}
		}
		return address;
	}

	bool test(std::string in, std::string expected) {
		static unsigned testNumber = 1;
		Stopwatch timer;
		timer.start();
		std::string out = defangIPaddr(in);
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
		success &= test("1.1.1.1", "1[.]1[.]1[.]1");
		success &= test("255.100.50.0", "255[.]100[.]50[.]0");
		success &= test("42.21.50.0", "42[.]21[.]50[.]0");
		return success;
	}
};

#endif // _SOL_1108_HPP_