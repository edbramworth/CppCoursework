#include <stdexcept>
#include <iostream>
#include <cassert>

#include "array2d.h"

int main(int argc, char *argv[]) {

	{ // Element-wise Operators
		{ // Multiplication
			{ // Check exception is not thrown when both arguments have the same size
				bool caught = false;
				try {
					array2d<int> x(2, 3, 1);
					array2d<int> y(2, 3, 2);

					array2d<int> z = x * y;
				}
				catch (const std::length_error &ex) {
					caught = true;
				}
				assert(!caught && "Incorrectly threw an exception even though args has the same width and height.");
			}
			{ // Check exception is thrown when either argument has a different size
				bool caught = false;
				try {
					array2d<int> x(2, 3, 1);
					array2d<int> y(3, 2, 2);

					array2d<int> z = x * y;
				}
				catch (const std::length_error &ex) {
					caught = true;
				}
				assert(caught && "Didn't throw an exception when args had different width or height.");
			}
		}
		{ // Division
			{ // Check exception is not thrown when both arguments have the same size
				bool caught = false;
				try {
					array2d<int> x(2, 3, 1);
					array2d<int> y(2, 3, 2);

					array2d<int> z = x / y;
				}
				catch (const std::length_error &ex) {
					caught = true;
				}
				assert(!caught && "Incorrectly threw an exception even though args has the same width and height.");
			}
			{ // Check exception is thrown when either argument has a different size
				bool caught = false;
				try {
					array2d<int> x(2, 3, 1);
					array2d<int> y(3, 2, 2);

					array2d<int> z = x / y;
				}
				catch (const std::length_error &ex) {
					caught = true;
				}
				assert(caught && "Didn't throw an exception when args had different width or height.");
			}
		}
		{ // Addition
			{ // Check exception is not thrown when both arguments have the same size
				bool caught = false;
				try {
					array2d<int> x(2, 3, 1);
					array2d<int> y(2, 3, 2);

					array2d<int> z = x + y;
				}
				catch (const std::length_error &ex) {
					caught = true;
				}
				assert(!caught && "Incorrectly threw an exception even though args has the same width and height.");
			}
			{ // Check exception is thrown when either argument has a different size
				bool caught = false;
				try {
					array2d<int> x(2, 3, 1);
					array2d<int> y(3, 2, 2);

					array2d<int> z = x + y;
				}
				catch (const std::length_error &ex) {
					caught = true;
				}
				assert(caught && "Didn't throw an exception when args had different width or height.");
			}
		}
		{ // Subtraction
			{ // Check exception is not thrown when both arguments have the same size
				bool caught = false;
				try {
					array2d<int> x(2, 3, 1);
					array2d<int> y(2, 3, 2);

					array2d<int> z = x - y;
				}
				catch (const std::length_error &ex) {
					caught = true;
				}
				assert(!caught && "Incorrectly threw an exception even though args has the same width and height.");
			}
			{ // Check exception is thrown when either argument has a different size
				bool caught = false;
				try {
					array2d<int> x(2, 3, 1);
					array2d<int> y(3, 2, 2);

					array2d<int> z = x - y;
				}
				catch (const std::length_error &ex) {
					caught = true;
				}
				assert(caught && "Didn't throw an exception when args had different width or height.");
			}
		}
	}
	{ // Self Element-wise Operators
		{ // Multiplication
			{ // Check exception is not thrown when both arguments have the same size
				bool caught = false;
				try {
					array2d<int> x(2, 3, 1);
					array2d<int> y(2, 3, 2);

					x *= y;
				}
				catch (const std::length_error &ex) {
					caught = true;
				}
				assert(!caught && "Incorrectly threw an exception even though args has the same width and height.");
			}
			{ // Check exception is thrown when either argument has a different size
				bool caught = false;
				try {
					array2d<int> x(2, 3, 1);
					array2d<int> y(3, 2, 2);

					x *= y;
				}
				catch (const std::length_error &ex) {
					caught = true;
				}
				assert(caught && "Didn't throw an exception when args had different width or height.");
			}
		}
		{ // Division
			{ // Check exception is not thrown when both arguments have the same size
				bool caught = false;
				try {
					array2d<int> x(2, 3, 1);
					array2d<int> y(2, 3, 2);

					x /= y;
				}
				catch (const std::length_error &ex) {
					caught = true;
				}
				assert(!caught && "Incorrectly threw an exception even though args has the same width and height.");
			}
			{ // Check exception is thrown when either argument has a different size
				bool caught = false;
				try {
					array2d<int> x(2, 3, 1);
					array2d<int> y(3, 2, 2);

					x /= y;
				}
				catch (const std::length_error &ex) {
					caught = true;
				}
				assert(caught && "Didn't throw an exception when args had different width or height.");
			}
		}
		{ // Addition
			{ // Check exception is not thrown when both arguments have the same size
				bool caught = false;
				try {
					array2d<int> x(2, 3, 1);
					array2d<int> y(2, 3, 2);

					x += y;
				}
				catch (const std::length_error &ex) {
					caught = true;
				}
				assert(!caught && "Incorrectly threw an exception even though args has the same width and height.");
			}
			{ // Check exception is thrown when either argument has a different size
				bool caught = false;
				try {
					array2d<int> x(2, 3, 1);
					array2d<int> y(3, 2, 2);

					x += y;
				}
				catch (const std::length_error &ex) {
					caught = true;
				}
				assert(caught && "Didn't throw an exception when args had different width or height.");
			}
		}
		{ // Subtraction
			{ // Check exception is not thrown when both arguments have the same size
				bool caught = false;
				try {
					array2d<int> x(2, 3, 1);
					array2d<int> y(2, 3, 2);

					x -= y;
				}
				catch (const std::length_error &ex) {
					caught = true;
				}
				assert(!caught && "Incorrectly threw an exception even though args has the same width and height.");
			}
			{ // Check exception is thrown when either argument has a different size
				bool caught = false;
				try {
					array2d<int> x(2, 3, 1);
					array2d<int> y(3, 2, 2);

					x -= y;
				}
				catch (const std::length_error &ex) {
					caught = true;
				}
				assert(caught && "Didn't throw an exception when args had different width or height.");
			}
		}
	}

	std::cout << "TEST PASS" << std::endl;
	return 0;
}