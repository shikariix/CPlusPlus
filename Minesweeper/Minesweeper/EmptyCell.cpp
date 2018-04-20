#include "EmptyCell.h"

EmptyCell::EmptyCell () {
}

EmptyCell::~EmptyCell () = default;

std::string EmptyCell::getType() {
	return "EmptyCell";
}

std::string EmptyCell::displayCell () {
	if (neighborMines == 0)	{
		return " ";
	} else {
		std::string s = std::to_string(neighborMines);
		return s;
	}
}

void EmptyCell::setNumber(int mines) {
	neighborMines = mines;
}
