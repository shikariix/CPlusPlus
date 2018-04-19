#include "Grid.h"
#include "Cell.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iterator>
#include "MineCell.h"
#include "EmptyCell.h"

Grid::Grid () {
	for (int i = 0; i < 20; i++) {
		std::vector<Cell*> tempVector;
		for (int j = 0; j < 20; j++) {
				int cellType = rand () % 10;
				if (cellType == 0) {
					tempVector.push_back (new MineCell ());
				}
				else {
					tempVector.push_back (new EmptyCell ());
				}
		}
		cells.push_back (tempVector);
	}
}

Grid::Grid (int width, int height) {
	this->width = width;
	this->height = height;
	srand (time (0));
	//Add cells to the grid
	for (int i = 0; i < height; i++) {
		std::vector<Cell*> tempVector;
		for (int j = 0; j < width; j++) {
			int cellType = rand () % 10;
			if (cellType == 0) {
				tempVector.push_back (new MineCell ());
			}
			else {
				tempVector.push_back (new EmptyCell ());
			}
		}
		cells.push_back (tempVector);
	}

	//Check neighbors of cells
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			//for every cell that is around the current one, check if it is a bomb
			int neighbors = 0;
			for (int k = i-1; k < i+2; k++) {
				for (int l = j-1; l < j+2; l++)
				{
					if (k >= 0 && l >= 0 && k < height && l < width && cells[k][l]->getType() == "MineCell") {
						neighbors++;
					}
				}
			}
			cells[i][j]->setNumber (neighbors);
		}
	}
}

void Grid::display() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << " " << cells[i][j]->displayCell() << " ";
		}
		std::cout << std::endl;
	}
}

Grid::~Grid()
{
	//delete all cells
}