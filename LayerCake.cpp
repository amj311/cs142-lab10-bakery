#include "LayerCake.h"

LayerCake::LayerCake(string initCake, string initFrosting, int initLayers) {
	itemString = initCake + initFrosting + to_string(initLayers);
	cakeFlavor = initCake;
	frostingFlavor = initFrosting;
	numLayers = initLayers;
	basePrice = 9.00;

	// Add $3 for every layer additional to 1
	basePrice += 3*(numLayers-1);

	// Upcharge for Cream Cheese frosting
	if (initFrosting == "cream-cheese") {
		basePrice += numLayers;
	}
}

LayerCake::~LayerCake() {
}

double LayerCake::DiscountedPrice(int typeQuantity) {
	if (typeQuantity >= 3) {
		return typeQuantity*(basePrice - 2.00);
	}

	else {
		return basePrice*typeQuantity;
	}
}

string LayerCake::ToString(){
	return to_string(numLayers) + "-layer "
		+ cakeFlavor + " cake with "
		+ frostingFlavor + " frosting "
		+ BakedGood::ToString();
}
