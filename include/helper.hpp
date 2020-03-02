#ifndef _LEET_HELPER_HPP_
#define _LEET_HELPER_HPP_

#include <iostream>

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