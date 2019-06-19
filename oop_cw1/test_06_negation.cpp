#include <cassert>
#include <iostream>

#include "array2d.h"

int main(int argc, char *argv[]) {

	{ // Negation Operator
		array2d<int> x(5, 5, 1);
		array2d<int> y = -x;
		assert(y(2, 2) == -1 && "Expected value at postion (2,2) to be -1.");
	}

	std::cout << "TEST PASS" << std::endl;
	return 0;
}