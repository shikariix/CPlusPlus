#include <iostream>
#include "Grid.h"
#include <string>

#define _ITERATOR_DEBUG_LEVEL 1

int main() {
	
	int width;
	int height;
	std::cout << "Enter grid width: " << std::endl;
	std::cin >> width;
	std::cout << "Enter grid height: " << std::endl;
	std::cin >> height;

	Grid grid = Grid (width, height);

	grid.display();

	char c;
	std::cin >> c;

	return 0;
}