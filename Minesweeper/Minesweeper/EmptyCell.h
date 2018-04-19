#pragma once
#include "Cell.h"

class EmptyCell : public Cell {
public:
	EmptyCell ();
	~EmptyCell ();
	std::string getType ();
	std::string displayCell() override;
	void setNumber (int mines) override;

private:
	Cell* neighbors[8];
	int neighborMines = 0;
	bool isVisible = false;
};

