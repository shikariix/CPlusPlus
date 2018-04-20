#include "MineCell.h"


MineCell::MineCell () = default;


MineCell::~MineCell () = default;

std::string MineCell::getType() {
	return "MineCell";
}

std::string MineCell::displayCell() {
	std::string s = "X";
	return s;
}

void MineCell::setNumber(int mines) {
}
