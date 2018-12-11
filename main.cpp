/*
Lab 10 - Bakery Invoice

Created by: Arthur Judd
Using: VS

Test Cases: I had multiple failed test cases when calculating discounts.
	The problem was a combination of small errors with operators or variable
	assignments. En fin, I should not try to code when I am so tired xD

*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "BakedGood.h"
#include "Bread.h"
#include "Cake.h"
#include "CupCake.h"
#include "LayerCake.h"

using namespace std;

int main() {
	vector<BakedGood*> orderItems;
	BakedGood* newItemPtr;
	string typeToCreate;
	int itemQuantity;
	
	//set precision
	cout << fixed << setprecision(2);

	cout << "**Bread and Cakes Bakery**" << endl << endl;
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;
	
	cout << "Sub-order: ";
	cin >> typeToCreate;

	cout << endl;

	//loop until typeToCreate == "done"
	while (typeToCreate != "done") {
		if (typeToCreate == "Bread") {
			//retrieve class-specific info
			string breadVariety;

			cin >> breadVariety;
			cin >> itemQuantity;

			for (int i = 0; i < itemQuantity; i++) {
				newItemPtr = new Bread(breadVariety);
				orderItems.push_back(newItemPtr);
			}
		}
		else if (typeToCreate == "Cupcake") {
			//retrieve class-specific info
			string cakeFlavor;
			string frostingFlavor;
			string sprinkleColor;

			cin >> cakeFlavor;
			cin >> frostingFlavor;
			cin >> sprinkleColor;
			cin >> itemQuantity;

			for (int i = 0; i < itemQuantity; i++) {
				newItemPtr = new CupCake(cakeFlavor, frostingFlavor, sprinkleColor);
				orderItems.push_back(newItemPtr);
			}
		}
		else if (typeToCreate == "Layer-cake") {
			//retrieve class-specific info
			string cakeFlavor;
			string frostingFlavor;
			int numLayers;

			cin >> cakeFlavor;
			cin >> frostingFlavor;
			cin >> numLayers;
			cin >> itemQuantity;

			for (int i = 0; i < itemQuantity; i++) {
				newItemPtr = new LayerCake(cakeFlavor, frostingFlavor, numLayers);
				orderItems.push_back(newItemPtr);
			}
		}

		cout << "Sub-order: ";
		cin >> typeToCreate;

	}	//end loop
	cout << endl;

	// Print Order Confirmation
	cout << "Order Confirmations:" << endl;
	for (unsigned int i = 0; i < orderItems.size(); i++) {
		cout << orderItems.at(i)->ToString() << endl;
	}

	
	//Print Invoice
	cout << endl << "Invoice:" << endl;

	//set labels
	cout << left << setw(75) << "Baked Good"
		<< right << setw(8) << "Quantity"
		<< setw(9) << "Total" << endl;

	//create invoice
	int typeQuantity;
	double typeTotalPrice;
	double invoiceTotalPrice = 0.00;

	vector<BakedGood*> invoiceList;

	for (int i = 0; i < orderItems.size(); i++) {
		//reset type-specific values
		typeQuantity = 0;
		typeTotalPrice = 0.00;

		if (orderItems.at(i)->NotInvoiced()) {
			cout << left << setw(75) << orderItems.at(i)->ToString();

			//search for similar items in orderItems
			for (int k = 0; k < orderItems.size(); k++) {
				if (orderItems.at(i)->GetItemString() == orderItems.at(k)->GetItemString()) {
					typeQuantity++;
					orderItems.at(k)->Invoice();
				}
			}

			//calculate total prices
			typeTotalPrice = orderItems.at(i)->DiscountedPrice(typeQuantity);
			invoiceTotalPrice +=typeTotalPrice;

			//print type info
			cout << right << setw(8) << typeQuantity
				<< setw(9) << typeTotalPrice << endl;
		}
		//else do nothing


	}
	
	//print totals
	cout << left << setw(75) << "Totals"
		<< right << setw(8) << orderItems.size()
		<< setw(9) << invoiceTotalPrice << endl;


	// Free memory
	// Looks like:
	//	{0,1,2}
	//	{0,1}
	//	{0}
	//	{}
	for (int i = orderItems.size()-1; i <= 0; i++) {
		delete orderItems.at(i);
	}

	cout << endl << "Good Bye" << endl;

	//system("pause");
	return 0;
}