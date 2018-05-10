#include "Grid.h"
#include "Cell.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iterator>
#include "MineCell.h"
#include "EmptyCell.h"

Grid::Grid () {
	makeCells ();
	checkNeighbors ();
}

Grid::Grid (int width, int height) {
	this->width = width;
	this->height = height;
	makeCells ();
	checkNeighbors ();
}

void Grid::display() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << " " << cells[i][j]->displayCell() << " ";
		}
		std::cout << std::endl;
	}
}


void Grid::makeCells() {
	srand (static_cast<int>(time (0)));
	//Add cells to the grid
	for (int i = 0; i < height; i++) {
		std::vector<Cell*> tempVector;
		for (int j = 0; j < width; j++) {
			int cellType = rand () % 10;
			if (cellType == 0) {
				tempVector.push_back (new MineCell ());
			}
			else {
				tempVector.push_back(new EmptyCell ());
			}
		}
		cells.push_back(tempVector);
	}

}

void Grid::checkNeighbors() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			//for every cell that is around the current one, check if it is a bomb
			int neighborBombs = 0;
			std::vector<Cell*> Neighbors;
			if (i > 0 ) {
				if (j > 0) {
					Neighbors.push_back (cells[i - 1][j - 1]);
				}
				Neighbors.push_back (cells[i - 1][j]);
				if (j < width - 1) {
					Neighbors.push_back (cells[i - 1][j + 1]);
				}
			}
			if (j < width - 1) {
				Neighbors.push_back (cells[i][j + 1]);
			}
			if (j > 0) {
				Neighbors.push_back (cells[i][j - 1]);
			}
			if (i < height - 1) {
				if (j < width - 1) {
					Neighbors.push_back (cells[i + 1][j + 1]);
				}
				Neighbors.push_back (cells[i + 1][j]);
				if (j > 0) {
					Neighbors.push_back (cells[i + 1][j - 1]);
				}
			}
			for (auto & Neighbor : Neighbors) {
				if (Neighbor->getType() == "MineCell") {
					neighborBombs++;
				}
			}

			cells[i][j]->setNumber(neighborBombs);
		}
	}
}

Grid::~Grid () {
	//delete all cells
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			delete cells[i][j];
		}
	}
}