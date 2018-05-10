#pragma once

#include "Cell.h"
#include <vector>

class Grid {
public:
	Grid ();
	Grid (int width, int height);
	void display ();
	void makeCells ();
	void checkNeighbors();
	~Grid();

private:
	int width = 20;
	int height = 20;

	std::vector<std::vector<Cell*>> cells;

};

