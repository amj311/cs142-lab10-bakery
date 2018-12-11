#pragma once
#include "BakedGood.h"

class Bread : public BakedGood {
public:
	Bread(string initVariety = "noVariety");
	~Bread();
	virtual string ToString();
	virtual double DiscountedPrice(int typeQuantity);
private:
	string variety;
};