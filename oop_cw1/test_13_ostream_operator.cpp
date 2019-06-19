#include <cassert>
#include <iostream>
#include <fstream>

#include "array2d.h"

int main(int argc, char *argv[]) {

	{ // std::ostream operator<<
		array2d<int> x(5, 5);

		for (size_t i = 0; i < x.get_width() * x.get_height(); i++) {
			x[i] = i;
		}

		// Print to console...
		std::cout << x << std::endl;

		{ // Print to file...
			std::ofstream file("ostream_output.txt", std::ios::out);
			if (file.is_open()) {
				file << x << std::endl;
			}
		}
	}

	std::cout << "TEST PASS" << std::endl;
	return 0;
}