#pragma once
#include "Cake.h"
class CupCake :
	public Cake
{
public:
	CupCake(string initCake = "noCakeFlavor", string initFrosting = "noFrosting", string initSprinkles = "noSprinklesColor");
	~CupCake();
	virtual double DiscountedPrice(int typeQuantity);
	virtual string ToString();
private:
	string sprinklesColor;
};