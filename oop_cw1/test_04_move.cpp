#include <cassert>
#include <iostream>

#include "array2d.h"

int main(int argc, char *argv[]) {

	{ // Move
		{ // y is move constructed from x
			array2d<int> x(5, 6, 42);
			array2d<int> y(std::move(x));

			// x should no longer have a resource
			assert(x.get_width() == 0 && "Expected result of get_width() to be 0.");
			assert(x.get_height() == 0 && "Expected result of get_height() to be 0.");

			// y should have the resource
			assert(y.get_width() == 5 && "Expected result of get_width() to be 5.");
			assert(y.get_height() == 6 && "Expected result of get_height() to be 6.");
			assert(y(2, 2) == 42 && "Expected value at postion (2,2) to be 42.");
		}
		{ // y is move constructed from x
			array2d<int> x(5, 6, 42);
			array2d<int> y = std::move(x);

			// x should no longer have a resource
			assert(x.get_width() == 0 && "Expected result of get_width() to be 0.");
			assert(x.get_height() == 0 && "Expected result of get_height() to be 0.");

			// y should have the resource
			assert(y.get_width() == 5 && "Expected result of get_width() to be 5.");
			assert(y.get_height() == 6 && "Expected result of get_height() to be 6.");
			assert(y(2, 2) == 42 && "Expected value at postion (2,2) to be 42.");
		}
		{ // y is constructed, then move assigned from x
			array2d<int> x(5, 6, 42);
			array2d<int> y(3, 3);
			y = std::move(x);

			// x should no longer have a resource
			assert(x.get_width() == 0 && "Expected result of get_width() to be 0.");
			assert(x.get_height() == 0 && "Expected result of get_height() to be 0.");

			// y should have the resource
			assert(y.get_width() == 5 && "Expected result of get_width() to be 5.");
			assert(y.get_height() == 6 && "Expected result of get_height() to be 6.");
			assert(y(2, 2) == 42 && "Expected value at postion (2,2) to be 42.");
		}
	}

	std::cout << "TEST PASS" << std::endl;
	return 0;
}