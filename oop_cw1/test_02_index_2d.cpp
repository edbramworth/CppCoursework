#include <cassert>
#include <iostream>

#include "array2d.h"

int main(int argc, char *argv[]) {

	{ // 2D Index Operator
		array2d<int> x(5, 6, 42);

		// Take a constant reference to x. 
		// This reference cannot have any function or operator 
		// called on it which isn't a const operator.
		const array2d<int> &cref_x = x;

		// Take a constant reference to the value in position 2,2.
		const int &y = cref_x(2, 2);
		assert(y == 42 && "Expected the value in position (2,2) to have value 42.");

		// Modify the value at position 2,2.
		// This requires a non-const reference.
		x(2, 2) = 10;
		assert(y == 10 && "Expected the value in position (2,2) to have value 10.");
	}

	std::cout << "TEST PASS" << std::endl;
	return 0;
}