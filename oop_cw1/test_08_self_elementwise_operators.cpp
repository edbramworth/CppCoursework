#include <cassert>
#include <iostream>

#include "array2d.h"

int main(int argc, char *argv[]) {

	{ // Self Element-wise Operators
		array2d<int> y(5, 5, 2);
		{ // Multiplication
			array2d<int> x(5, 5, 4);
			x *= y;
			assert(x(2, 2) == 8 && "Expected value at postion (2,2) to be 8.");
		}
		{ // Division
			array2d<int> x(5, 5, 4);
			x /= y;
			assert(x(2, 2) == 2 && "Expected value at postion (2,2) to be 2.");
		}
		{ // Addition
			array2d<int> x(5, 5, 4);
			x += y;
			assert(x(2, 2) == 6 && "Expected value at postion (2,2) to be 6.");
		}
		{ // Subtraction
			array2d<int> x(5, 5, 4);
			x -= y;
			assert(x(2, 2) == 2 && "Expected value at postion (2,2) to be 2.");
		}
	}

	std::cout << "TEST PASS" << std::endl;
	return 0;
}