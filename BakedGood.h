#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

class BakedGood {
public:
	BakedGood();
	~BakedGood();
	string GetItemString() {
		return itemString;
	}
	void Invoice() {
		isNotInvoiced = false;
	}
	bool NotInvoiced() {
		return isNotInvoiced;
	}
	virtual string ToString();
	virtual double DiscountedPrice(int itemQuantity) = 0;
protected:
	string itemString;
	double basePrice;
	bool isNotInvoiced = true;
};