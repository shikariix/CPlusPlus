#pragma once
#include "Cell.h"

class MineCell : public Cell {
public:
	MineCell ();
	~MineCell ();
	std::string getType () override;
	std::string displayCell() override;
	void setNumber (int mines) override;

private:
	bool isVisible = false;
};

