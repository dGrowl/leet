#ifdef   SOLUTION
#include SOLUTION
#else
#include "solutions/-1.hpp"
#endif

int main() {
	Solution s;
	Stopwatch timer;
	timer.start();
	const bool success = s.runTests();
	timer.stop();
	std::cout << SOLUTION;
	if (success) {
		std::cout << " PASSED [" << timer.report() << "s]" << std::endl;
	}
	else {
		std::cout << " FAILED [" << timer.report() << "s]" << std::endl;
	}
	return 0;
}
