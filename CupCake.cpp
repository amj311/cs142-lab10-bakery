#include "CupCake.h"


CupCake::CupCake(string initCake, string initFrosting, string initSprinkles) {
	itemString = initCake + initFrosting + initSprinkles;
	cakeFlavor = initCake;
	frostingFlavor = initFrosting;
	sprinklesColor = initSprinkles;
	basePrice = 1.95;
	// Upcharge for Cream Cheese frosting
	if (initFrosting == "cream-cheese") {
		basePrice += .20;
	}
}


CupCake::~CupCake() {

}

double CupCake::DiscountedPrice(int typeQuantity) {
	if (typeQuantity >= 4) {
		return typeQuantity*(basePrice - 0.40);
	}
	else if(typeQuantity >= 2) {
		return typeQuantity*(basePrice - 0.30);
	}

	else {
		return typeQuantity*basePrice;
	}
}

string CupCake::ToString() {
	return cakeFlavor + " cupcake with "
		+ frostingFlavor + " frosting and "
		+ sprinklesColor + " sprinkles "
		+ BakedGood::ToString();
}