#include "Bread.h"



Bread::Bread(string setVariety) {
	itemString = setVariety;
	variety = setVariety;
	basePrice = 4.50;
}


Bread::~Bread(){
}

string Bread::ToString() {
	return variety + " bread " + BakedGood::ToString();
}

double Bread::DiscountedPrice(int typeQuantity) {
	double totalPrice = 0.00;
	
	for (int i = 0; i < typeQuantity; i++) {
		if ((i+1) % 3 != 0) {
			totalPrice += basePrice;
		}
	}

	return totalPrice;
}
