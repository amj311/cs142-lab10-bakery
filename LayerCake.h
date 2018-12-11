#pragma once
#include "Cake.h"

class LayerCake : public Cake {
public:
	LayerCake(string initCake = "noCakeFlavor", string initFrosting = "noFrosting", int initLayers = 0);
	~LayerCake();
	virtual double DiscountedPrice(int typeQuantity);
	virtual string ToString();
private:
	int numLayers;
};