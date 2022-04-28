#include "Product.h"
#include <iostream>
using namespace std;

Product::Product() {
	initProduct();
}

Product::~Product() {
	delete[] mProdName;
	delete[] mManifacName;
}

//setters
void Product::initProduct() {
	cout << "--------------\n";
	cout << "Product Initialization\n";
	cout << "--------------\n";

	setProdName();
	cout << "Expire date\n";
	mExpireDate.init();
	cout << "Entry date\n";
	mEntryDate.init();
	setManifacName();
	setQuantity();
	mLocation.initPlace();
	setComment();

	cout << "--------------\n";
	cout << "Product Initialized Successfully!\n";
	cout << "--------------\n";
}

void Product::setProdName() {
	cout << "Product name: ";
	char input[MAX_LEN];
	cin >> input;
	mProdName = new char[strlen(input) + 1];
	strcpy_s(mProdName, strlen(input) + 1, input);
}

void Product::setManifacName() {
	cout << "Manifacturer name: ";
	char input[MAX_LEN];
	cin >> input;
	mManifacName = new char[strlen(input) + 1];
	strcpy_s(mManifacName, strlen(input) + 1, input);
}

void Product::setQuantity() {
	cout << "Quantity: ";
	cin >> mQuantity;
}

void Product::setComment() {
	cout << "Short comment (MAX 1024 symbols): ";
	do {
	cin >> mComment;
	if (strlen(mComment) < MAX_LEN) {
		cout << "Comment added!\n";
	}
	else {
		cout << "Comment too long\n";
	}
	} while (strlen(mComment) > MAX_LEN - 1);
}

//getters
void Product::printProduct()const {
	cout << "--------------\n";
	cout << "Product Information\n";
	cout << "--------------\n";

	cout << "Product name: " << getProdName();
	cout << "Expire date\n" << "Year: " << mExpireDate.getYear()
							<< "Month: " << mExpireDate.getMonth()
							<< "Day: " << mExpireDate.getDay();
	cout << "Entry date\n" << "Year: " << mEntryDate.getYear()
						   << "Month: " << mEntryDate.getMonth()
						   << "Day: " << mEntryDate.getDay();
	cout << "Manifacturer name: " << getManifacName();
	cout << "Quantity: " << getQuantity();
	cout << "Location\n" << "Section: " << mLocation.getSection()
						 << "Shelf: " << mLocation.getShelf()
						 << "Id: " << mLocation.getId();
	cout << "Comment: " << getComment();
	
}

const char* Product::getProdName()const {
	return mProdName;
}

const char* Product::getManifacName()const {
	return mManifacName;
}

unsigned int Product::getQuantity()const {
	return mQuantity;
}

const char* Product::getComment()const {
	return mComment;
}