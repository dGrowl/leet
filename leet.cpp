#include <iostream>

#ifdef   SOLUTION
#include SOLUTION
#else
#include "solutions/-1.hpp"
#endif

int main() {
	Solution s;
	const bool success = s.runTests();
	std::cout << SOLUTION;
	if (success) {
		std::cout << " PASSED" << std::endl;
	}
	else {
		std::cout << " FAILED" << std::endl;
	}
	return 0;
}
