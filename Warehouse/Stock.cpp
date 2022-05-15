#include "Stock.h"
#include <iostream>
#include <fstream>
using namespace std;
#define FILENAME "Stock.txt"

//Utils - help-functions
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
					//save the product to the file
					Product::write(FILENAME, product);
				}
				else {
					cout << "No space available!";
				}
			}
		}
	}
}

//help-function for the validation of the date
bool isValidDate(size_t year, size_t month, size_t day) {
	bool valid = false;
	//validation of the date
	if (MIN_YEAR <= year <= MAX_YEAR) {
		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 0 && day <= 31) {
			cout << "Valid date!\n";
			valid = true;
		}
		else {
			if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 0 && day <= 30) {
				cout << "Valid date!\n";
				valid = true;
			}
			else {
				if (month == 2) {
					if ((year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) && day > 0 && day <= 29) {
						cout << "Valid date!\n";
						valid = true;
					}
					else if (day > 0 && day <= 28) {
						cout << "Valid date!\n";
						valid = true;
					}
					else {
						cout << "Invalid date!\n";
						valid = false;
					}
				}
				else {
					cout << "Invalid date!\n";
					valid = false;
				}
			}
		}
	}
	else {
		cout << "Invalid date!\n";
		valid = false;
	}
	return valid;
}

//save the product to a file
void Stock::saveToFile() {
	for (size_t section = 0; section < SECTIONS; section++){
		for (size_t shelf = 0; shelf < SHELVES; shelf++){
			for (size_t shelfPos = 0; shelfPos < SHELF_POS; shelfPos++){
				if (mProducts[section][shelf][shelfPos] != nullptr) { //if the product exists add it to the file
					Product::write(FILENAME, *mProducts[section][shelf][shelfPos]);
				}
			}
		}
	}
}
// -------------------------------------------

//Main functions for the menu

//this function will add new product
void Stock::addProducts(const Product& product) {
	for (size_t i = 0; i < SECTIONS; i++) { //sections
		for (size_t j = 0; j < SHELVES; j++) { //shelves
			for (size_t k = 0; k < SHELF_POS; k++) { //position in the shelf
				// wanted conditions for a product to be added
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
	saveToFile(); // save the information to a file
}

//this function will display all details of all products available in the Warehouse
void Stock::displayProducts() {
	size_t quantityOfProdWithSameName = 0;
	for (size_t currSec = 0; currSec < SECTIONS; currSec++) {
		for (size_t currShelf = 0; currShelf < SHELVES; currShelf++) {
			for (size_t currShelfPos = 0; currShelfPos < SHELF_POS; currShelfPos++) {
				//at this position there is a product so we print it
				if (mProducts[currSec][currShelf][currShelfPos] != nullptr) {
					//compare the name of the current product with the name of the other products in the warehouse
					for (size_t otherSec = 0; otherSec < SECTIONS; otherSec++) {
						for (size_t otherShelf = 0; otherShelf < SHELVES; otherShelf++) {
							for (size_t otherShelfPos = 0; otherShelfPos < SHELF_POS; otherShelfPos++) {
								if (strcmp(mProducts[currSec][currShelf][currShelfPos]->getProdName(), mProducts[otherSec][otherShelf][otherShelfPos]->getProdName()) == 0) {
									quantityOfProdWithSameName += mProducts[otherSec][otherShelf][otherShelfPos]->getQuantity();
								}
							}
						}
					}
					quantityOfProdWithSameName += mProducts[currSec][currShelf][currShelfPos]->getQuantity();
					//print the current product and then the whole quantity with the same name
					mProducts[currSec][currShelf][currShelfPos]->printProduct();
					cout << endl;
					cout << "Whole quantity of products with the same name: " << quantityOfProdWithSameName << endl; //the total quantity of products of the same name, regardless of their expire date
					quantityOfProdWithSameName = 0;
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
	//create the min date - needed for the second bullet point, but I am not sure how to make it
	//Date expiringSoon;
	//this could also be done with a constructor
	//expiringSoon.setYearNum(MIN_YEAR);
	//expiringSoon.setMonthNum(1);
	//expiringSoon.setDayNum(1);

	cout << "Enter the name of the product you want to remove: ";
	cin >> inputName;

	cout << "Enter the quantity of the product you want to remove: ";
	cin >> inputQuantity;

	for (size_t i = 0; i < SECTIONS; i++) {
		for (size_t j = 0; j < SHELVES; j++) {
			for (size_t k = 0; k < SHELF_POS; k++) {
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
						case 'y': mProducts[i][j][k] = nullptr; cout << "Product has been removed!" << endl; break;
						case 'n': cout << "No products are removed!" << endl; break;
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
	saveToFile();
}

//this function will check if a product is available
//not completed because I am not sure how to do it
bool Stock::availabilityCheck() {
	int year1, year2;
	int month1, month2;
	int day1, day2;
	//range of dates
	//date 1
	cout << "Date1 Year: ";
	cin >> year1;
	cout << "Date1 Month: ";
	cin >> month1;
	cout << "Date1 Day: ";
	cin >> day1;

	while (!isValidDate(year1, month1, day1)) {
		cout << "Date1 Year: ";
		cin >> year1;
		cout << "Date1 Month: ";
		cin >> month1;
		cout << "Date1 Day: ";
		cin >> day1;
	}
	//date 2
	cout << "Current Year: ";
	cin >> year2;
	cout << "Current Month: ";
	cin >> month2;
	cout << "Current Day: ";
	cin >> day2;

	while (!isValidDate(year2, month2, day2)) {
		cout << "Current Year: ";
		cin >> year2;
		cout << "Current Month: ";
		cin >> month2;
		cout << "Current Day: ";
		cin >> day2;
	}
	//and here we should do something with the range of the two dates to print the products in the given period 
}

//clears up the warehouse
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

	while (!isValidDate(year,month,day)) {
		cout << "Current Year: ";
		cin >> year;
		cout << "Current Month: ";
		cin >> month;
		cout << "Current Day: ";
		cin >> day;
	}

	//create the name of the file
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
	for (size_t currSec = 0; currSec < SECTIONS; currSec++) {
		for (size_t currShelf = 0; currShelf < SHELVES; currShelf++) {
			for (size_t currShelfPos = 0; currShelfPos < SHELF_POS; currShelfPos++) {
				if (mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getYear() == year &&
					mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getMonth() == month &&
					mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getDay() == day) {
					//save to file the product that will be removed
					Product::write(fileName, *mProducts[currSec][currShelf][currShelfPos]);
					//remove the product
					mProducts[currSec][currShelf][currShelfPos] = nullptr;
				}
				else if (mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getYear() == year || mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getYear() < year &&
					mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getMonth() < month || mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getYear() == year &&
					mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getMonth() == month && mProducts[currSec][currShelf][currShelfPos]->getExpireDate().getDay() < day) {
					//save to file the product that will be removed
					Product::write(fileName, *mProducts[currSec][currShelf][currShelfPos]);
					//remove the product
					mProducts[currSec][currShelf][currShelfPos] = nullptr;
				}
			}
		}
	}
	//read it from a file and print the information for the removed products
	Product::read(fileName);
}