#include <cassert>
#include <iostream>

#include "array2d.h"

int main(int argc, char *argv[]) {

	{ // Scalar Assignment Operator
		array2d<int> x(5, 5);
		x = 42;
		assert(x(2, 2) == 42 && "Expected value at postion (2,2) to be 42.");
	}

	std::cout << "TEST PASS" << std::endl;
	return 0;
}