#include <cassert>
#include <iostream>

#include "array2d.h"

int main(int argc, char *argv[]) {

	{ // Copy
		array2d<int> x(6, 5, 42);
		{ // y is copy constructed from x
			array2d<int> y(x);
			assert(y.get_width()  == 6 && "Expected result of get_width() to be 6.");
			assert(y.get_height() == 5 && "Expected result of get_height() to be 5.");
			assert(y(2,2) == 42        && "Expected value at postion (2,2) to be 42.");
		}
		{ // y is copy constructed from x
			array2d<int> y = x;
			assert(y.get_width()  == 6 && "Expected result of get_width() to be 6.");
			assert(y.get_height() == 5 && "Expected result of get_height() to be 5.");
			assert(y(2,2) == 42        && "Expected value at postion (2,2) to be 42.");
		}
		{ // y is default constructed, then copy assigned from x
			array2d<int> y;
			y = x;
			assert(y.get_width()  == 6 && "Expected result of get_width() to be 6.");
			assert(y.get_height() == 5 && "Expected result of get_height() to be 5.");
			assert(y(2,2) == 42        && "Expected value at postion (2,2) to be 42.");
		}
		{ // z is default constructed, then copy assigned from y, y leaves scope, but z should still have its own copy
			array2d<int> z;
			{
				array2d<int> y(6, 5, 10);
				z = y;
			}
			assert(z.get_width()  == 6 && "Expected result of get_width() to be 6.");
			assert(z.get_height() == 5 && "Expected result of get_height() to be 5.");
			assert(z(2,2) == 10        && "Expected value at postion (2,2) to be 10.");
		}
		assert(x.get_width()  == 6 && "Expected result of get_width() to be 6.");
		assert(x.get_height() == 5 && "Expected result of get_height() to be 5.");
		assert(x(2,2) == 42        && "Expected value at postion (2,2) to be 42.");
	}

	std::cout << "TEST PASS" << std::endl;
	return 0;
}