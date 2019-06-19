#include <cassert>
#include <iostream>

#include "array2d.h"

int main(int argc, char *argv[]) {

	{ // Cast Operator
		array2d<double> x(5, 5, 42.1);
		array2d<int> y = (array2d<int>) x;
		assert(y(2, 2) == 42 && "Expected value at postion (2,2) to be 42.");
	}

	std::cout << "TEST PASS" << std::endl;
	return 0;
}