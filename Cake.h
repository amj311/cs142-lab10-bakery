#pragma once
#include "BakedGood.h"

class Cake : public BakedGood {
public:
	Cake();
	~Cake();
protected:
	string cakeFlavor;
	string frostingFlavor;
};

