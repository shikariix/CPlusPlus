#pragma once
#include <string>

class Cell {
public:
	virtual ~Cell ();
	virtual std::string displayCell () = 0;
	virtual std::string getType () = 0;
	virtual void setNumber (int mines) = 0;

	bool isVisible = false;
};

