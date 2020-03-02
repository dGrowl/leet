#ifndef _LEET_HELPER_HPP_
#define _LEET_HELPER_HPP_

#include <chrono>
#include <iostream>

class Stopwatch {
private:
	std::chrono::time_point<std::chrono::steady_clock> begin;
	std::chrono::time_point<std::chrono::steady_clock> end;
public:
	void start() {
		begin = std::chrono::steady_clock::now();
	}
	void stop() {
		end = std::chrono::steady_clock::now();
	}
	void reset() {
		begin = std::chrono::time_point<std::chrono::steady_clock>();
		end = std::chrono::time_point<std::chrono::steady_clock>();
	}
	auto report() {
		std::chrono::duration<double> duration = end - begin;
		return duration.count();
	}
};

template <typename T> 
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) { 
	out << "[ ";
	if (!vec.empty()) {
		out << vec[0];
		for (unsigned i = 1; i < vec.size(); ++i) {
			out << ", " << vec[i];
		}
	}
	out << " ]";
	return out; 
} 

#endif // _LEET_HELPER_HPP_