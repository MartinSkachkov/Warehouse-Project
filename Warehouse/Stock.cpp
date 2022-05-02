#include "Stock.h"
#include <iostream>
using namespace std;

//needed for bool Stock::productWithSameName(const Product& other); function
//these two variable will store the index i and j from a for loop(the position of the product with the same name)
size_t sectionPos;
size_t shelfPos;
size_t countProdSameName = 0;

//Utils
// -------------------------------------------
//this function sets every place to empty to indicate there is no product in the beginning
//0 - empty
//1 - non-empty
void Stock::setEveryPlaceToEmpty() {
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			mProducts[i][j].getPlace().setEmptyPlace(0);
		}
	}
}

//this function will check if there is a product with the same name
bool Stock::productWithSameName(const Product& other)const {
	for (size_t i = 0; i < SECTIONS; i++) {
		for (size_t j = 0; j < SHELVES; j++) {
			if (strcmp(mProducts[i][j].getProdName(), other.getProdName()) == 0) {
				sectionPos = i;
				shelfPos = j;
				return true;
				break;
			}
		}
	}
	return false;
}

//this function will count products with same name and return their number
size_t Stock::countProductWithSameName(const Product& other)const {
	for (size_t i = 0; i < SECTIONS; i++) {
		for (size_t j = 0; j < SHELVES; j++) {
			if (strcmp(mProducts[i][j].getProdName(), other.getProdName()) == 0) {
				countProdSameName++;
			}
		}
	}
	return countProdSameName;
}

// -------------------------------------------

//this function will add new product
void Stock::createProducts() {
	Product newProduct;//constr for newProduct which will call the product initialization function
	for (size_t i = 0; i < SECTIONS; i++) {
		for (size_t j = 0; j < SHELVES; j++) {
			if (mProducts[i][j].getPlace().getEmptyPlace() != 1 && productWithSameName(newProduct)) { // we found an empty place and a product with a same name we want to add
				// wanted conditions for a product to be added
				if (newProduct.getExpireDate() != mProducts[sectionPos][shelfPos].getExpireDate()) { //op!= for dates
					mProducts[i][j] = newProduct;//op=
					// insert at that location our new product
					mProducts[i][j].getPlace().setSection(i);
					mProducts[i][j].getPlace().setShelf(j);
				}
			}
			else {
				cout << "No space available!";
			}
		}
	}
}

//this function will display all details of all products available in the Warehouse
void Stock::displayProducts()const {
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 10; j++) {
			if (mProducts[i][j].getPlace().getEmptyPlace() == 1){
				mProducts[i][j].printProduct();
				cout << endl;
				cout << "Quantity of products with the same name: " << countProdSameName; //the total quantity of products of the same name, regardless of their expire date
			}

		}
	}
}

//this function will remove a product
void removeProducts() {
	int inputQuantity;
	char inputName[MAX_LEN];

	cout << "Enter the name of the product you want to remove: ";
	cin >> inputName;

	cout << "Enter the quantity of the product you want to remove: ";
	cin >> inputQuantity;
}