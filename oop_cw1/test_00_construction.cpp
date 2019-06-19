#include <cassert>
#include <iostream>

#include "array2d.h"

int main(int argc, char *argv[]) {

	{ // Construction and Accessors
		{ // Construct with size 0 x 0 and no memory
			array2d<int> x;

			assert(x.get_width()  == 0 && "Expected result of get_width() to be 0.");
			assert(x.get_height() == 0 && "Expected result of get_height() to be 0.");

			// Check accessors can be called from const object
			const array2d<int> &y = x;
			assert(y.get_width() == 0 && "Expected result of get_width() to be 0.");
			assert(y.get_height() == 0 && "Expected result of get_width() to be 0.");
		}
		{ // Construct with 2D size
			array2d<int> x(5, 5);

			assert(x.get_width()  == 5 && "Expected result of get_width() to be 5.");
			assert(x.get_height() == 5 && "Expected result of get_height() to be 5.");
		}
		{ // Construct with degenerate 2D size
			array2d<int> x(0, 0);

			assert(x.get_width() == 0 && "Expected result of get_width() to be 0.");
			assert(x.get_height() == 0 && "Expected result of get_height() to be 0.");
		}
		{ // Construct with 2D size and default value
			array2d<int> x(5, 5, 42);

			assert(x.get_width()  == 5 && "Expected result of get_width() to be 5.");
			assert(x.get_height() == 5 && "Expected result of get_height() to be 5.");
		}
		{ // Construct with degenerate 2D size and default value
			array2d<int> x(0, 0, 42);

			assert(x.get_width() == 0 && "Expected result of get_width() to be 0.");
			assert(x.get_height() == 0 && "Expected result of get_height() to be 0.");
		}
	}

	std::cout << "TEST PASS" << std::endl;
	return 0;
}