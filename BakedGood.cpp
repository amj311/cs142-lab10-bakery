#include "BakedGood.h"

BakedGood::BakedGood() {}


BakedGood::~BakedGood() {}

string BakedGood::ToString() {
	stringstream printString;
	printString << fixed << setprecision(2) << "($" << basePrice << ")";

	return printString.str();
}
