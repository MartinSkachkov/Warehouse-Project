#include "Stock.h"
#include <iostream>
using namespace std;
#define FILENAME "Stock.txt"

//Utils
// -------------------------------------------
//this function sets every place to empty to indicate there is no product in the beginning
void Stock::setEveryPlaceToEmpty() {
	for (size_t i = 0; i < SECTIONS; i++)
	{
		for (size_t j = 0; j < SHELVES; j++)
		{
			for (size_t k = 0; k < SHELF_POS; k++)
			{
				mProducts[i][j][k] = nullptr;
			}
		}
	}
}

//this function will create an object of type product
void Stock::createProducts() {
	Product newProduct;//constr for newProduct which will call the product initialization function
	addProducts(newProduct);//then we add this product to our stock
}

//this function will set a product at an empty space
void Stock::setProducts(const Product& product) {
	for (size_t i = 0; i < SECTIONS; i++)
	{
		for (size_t j = 0; j < SHELVES; j++)
		{
			for (size_t k = 0; k < SHELF_POS; k++)
			{
				if (mProducts[i][j][k] == nullptr) {
					*mProducts[i][j][k] = product; //the pointer is initialized and indicates that now there is a product
					mProducts[i][j][k]->getPlace().setSection(i);
					mProducts[i][j][k]->getPlace().setShelf(j);
					mProducts[i][j][k]->getPlace().setShelfPos(k);
				}
				else {
					cout << "No space available!";
				}
			}
		}
	}
}

//this function will tell the number of repetitions of a product
int Stock::productsWithSameName() {
	for (size_t currSec = 0; currSec < SECTIONS; currSec++)
	{
		for (size_t j = 0; j < SHELVES; j++)
		{
			for (size_t i = 0; i < SHELF_POS-1; i++)
			{
				for (size_t i = 0; i < length; i++)
				{

				}
			}
		}
	}
}
// -------------------------------------------

//this function will add new product
size_t wholeQuantity = 0;
void Stock::addProducts(const Product& product) {
	for (size_t i = 0; i < SECTIONS; i++) {
		for (size_t j = 0; j < SHELVES; j++) {
			for (size_t k = 0; k < SHELF_POS; k++) {
				// wanted conditions for a product to be added
				if (strcmp(mProducts[i][j][k]->getProdName(), product.getProdName()) == 0) {
					wholeQuantity += mProducts[i][j][k]->getQuantity() + product.getQuantity();
				}
				if (strcmp(mProducts[i][j][k]->getProdName(), product.getProdName()) == 0 && mProducts[i][j][k]->getExpireDate() != product.getExpireDate()) { //op!= for dates
					// insert at empty location our new product
					setProducts(product);
					return;
				}
				if (strcmp(mProducts[i][j][k]->getProdName(), product.getProdName()) == 0 && mProducts[i][j][k]->getExpireDate() == product.getExpireDate()) { //op== for dates
					//adjacent shelf position
					for (size_t currShelfPos = 0; currShelfPos < SHELF_POS; currShelfPos++)
					{
						//find a place on the same shelf
						if (mProducts[i][j][currShelfPos] == nullptr) {
							*mProducts[i][j][currShelfPos] = product;
							mProducts[i][j][currShelfPos]->getPlace().setSection(i);
							mProducts[i][j][currShelfPos]->getPlace().setShelf(j);
							mProducts[i][j][currShelfPos]->getPlace().setShelfPos(currShelfPos);
							return; //found a place and added the product, but if not continue
						}
					}
					//adjacent shelf
					size_t currShelf;
					size_t max_shelf = 10;
					for (currShelf = j; currShelf < max_shelf; currShelf++)
					{
						for (size_t currShelfPos = 0; currShelfPos < SHELF_POS; currShelfPos++)
						{
							if (mProducts[i][currShelf][currShelfPos] == nullptr) {
								*mProducts[i][currShelf][currShelfPos] = product;
								mProducts[i][currShelf][currShelfPos]->getPlace().setSection(i);
								mProducts[i][currShelf][currShelfPos]->getPlace().setShelf(currShelf);
								mProducts[i][currShelf][currShelfPos]->getPlace().setShelfPos(currShelfPos);
								return;
							}
						}
						if (currShelf == 9 && j != 0) {
							currShelf = 0;
							max_shelf = j;
						}
					}
					//adjacent sections
					for (size_t currSection = 0; currSection < SECTIONS; currSection++)
					{
						for (size_t currShelf = 0; currShelf < SHELVES; currShelf++)
						{
							for (size_t currShelfPos = 0; currShelfPos < SHELF_POS; currShelfPos++)
							{
								if (mProducts[currSection][currShelf][currShelfPos] == nullptr) {
									*mProducts[currSection][currShelf][currShelfPos] = product;
									mProducts[currSection][currShelf][currShelfPos]->getPlace().setSection(currSection);
									mProducts[currSection][currShelf][currShelfPos]->getPlace().setShelf(currShelf);
									mProducts[currSection][currShelf][currShelfPos]->getPlace().setShelfPos(currShelfPos);
									return;
								}
							}
						}
					}
					cout << "No space available!";
				}
				//if we haven't returned from the above 'ifs' then add the product somewhere if there is space 
				setProducts(product);
				return;
			}
		}
	}
}

//this function will display all details of all products available in the Warehouse
void Stock::displayProducts() {
	for (size_t i = 0; i < SECTIONS; i++) {
		for (size_t j = 0; j < SHELVES; j++) {
			for (size_t k = 0; k < SHELF_POS; k++) {
				//at this position there is a product so we print it
				if (mProducts[i][j][k] != nullptr) {
					mProducts[i][j][k]->printProduct();
					cout << endl;
					//cout << "Quantity of products with the same name: " << wholeQuantity; //the total quantity of products of the same name, regardless of their expire date
					//wholeQuantity = 0;
				}
			}
		}
	}
}

//this function will remove a product
void Stock::removeProducts() {
	size_t inputQuantity;
	size_t newQuantity;
	char inputName[MAX_LEN];

	cout << "Enter the name of the product you want to remove: ";
	cin >> inputName;

	cout << "Enter the quantity of the product you want to remove: ";
	cin >> inputQuantity;

	for (size_t i = 0; i < SECTIONS; i++){
		for (size_t j = 0; j < SHELVES; j++){
			for (size_t k = 0; k < SHELF_POS; k++){
				if (strcmp(mProducts[i][j][k]->getProdName(), inputName) == 0) {
					if (mProducts[i][j][k]->getQuantity() < inputQuantity) {
						cout << "Quantity of the product: " << mProducts[i][j][k]->getQuantity();
						cout << "Expiring date of the product\n";
						cout << "Year: " << mProducts[i][j][k]->getExpireDate().getYear() << endl;
						cout << "Month: " << mProducts[i][j][k]->getExpireDate().getMonth() << endl;
						cout << "Day: " << mProducts[i][j][k]->getExpireDate().getDay() << endl;

						cout << "Do you want to remove what is left?(y/n)";
						char decision;
						do {
							cin >> decision;
							if (decision != 'y' && decision != 'n') {
								cout << "Invalid key typed! Type 'y' or 'n': ";
							}
						} while (decision != 'y' && decision != 'n');
						switch (decision)
						{
						case 'y': mProducts[i][j][k] = nullptr; cout << "Product has been removed!"; break;
						case 'n': cout << "No products are removed!"; break;
						}
					}
					if (mProducts[i][j][k]->getQuantity() > 0 && mProducts[i][j][k]->getQuantity() > inputQuantity) {
						newQuantity = mProducts[i][j][k]->getQuantity() - inputQuantity;
						mProducts[i][j][k]->updateQuantity(newQuantity);
					}
				}
			}
		}
	}
}

void Stock::clearingUp() {
	//validation
	int year;
	int month;
	int day;
	cout << "Current Year: ";
	cin >> year;
	cout << "Current Month: ";
	cin >> month;
	cout << "Current Day: ";
	cin >> day;

	char fileName[] = "cleanup-YYYY-MM-DD.txt";
	fileName[8] = year / 1000 + '0';
	fileName[9] = (year / 100) % 10 + '0';
	fileName[10] = (year / 10) % 10 + '0';
	fileName[11] = year % 10 + '0';
	fileName[13] = month / 10 + '0';
	fileName[14] = month % 10 + '0';
	fileName[16] = day / 10 + '0';
	fileName[17] = day % 10 + '0';

	//disposal of all expired goods
	for (size_t currSec = 0; currSec < SECTIONS; currSec++){
		for (size_t currShelf = 0; currShelf < SHELVES; currShelf++) {
			for (size_t currShelfPos = 0; currShelfPos < SHELF_POS; currShelfPos++) {
				if (mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getYear() == year &&
					mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getMonth() == month &&
					mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getDay() == day) {
					//save to file
					Product::write(fileName, *mProducts[currSec][currShelf][currShelfPos]);
					mProducts[currSec][currShelf][currShelfPos] = nullptr;
				}
				else if (mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getYear() == year || mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getYear() < year &&
					mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getMonth() < month || mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getYear() == year &&
					mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getMonth() == month && mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getDay() < day){
					//save to file
					mProducts[currSec][currShelf][currShelfPos] = nullptr;
				}
			}
		}
	}
	//display read
}