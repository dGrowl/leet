# leet

Organized collection of personal LeetCode solutions written in C++.

### Usage

Build a particular solution by invoking make with a specified problem number.

`$ make N=42`

Alternatively, manually specify a solution header file by defining the SOLUTION preprocessor constant.

`$ g++ leet.cpp -I. -D SOLUTION=\"solutions/42.hpp\" -o leet`