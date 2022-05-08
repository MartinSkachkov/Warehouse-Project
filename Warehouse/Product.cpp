#include "Product.h"
#include <iostream>
using namespace std;

void Product::copyFrom(const Product& source) {
	mProdName = new char[strlen(source.mProdName) + 1];
	strcpy_s(mProdName, strlen(source.mProdName) + 1, source.mProdName);
	mExpireDate = source.mEntryDate; // op=?
	mEntryDate = source.mEntryDate;
	mManifacName = new char[strlen(source.mManifacName) + 1];
	strcpy_s(mManifacName, strlen(source.mManifacName) + 1, source.mManifacName);
	mQuantity = source.mQuantity;
	mLocation = source.mLocation; // op=?
	strcpy_s(mComment, MAX_LEN, source.mComment);
}

void Product::free() {
	delete[] mProdName;
	delete[] mManifacName;
}

Product::Product() {
	initProduct();
}

Product::Product(const Product& source) {
	copyFrom(source);
}

Product& Product::operator=(const Product& source) {
	if (this == &source) {
		return *this;
	}
	free();
	copyFrom(source);
	return *this;
}

Product::~Product() {
	free();
}

//helpful functions
void Product::initProduct() {
	cout << "----------------------\n";
	cout << "Product Initialization\n";
	cout << "----------------------\n";

	setProdName();
	cout << "Expire date\n";
	mExpireDate.init();
	cout << "Entry date\n";
	mEntryDate.init();
	setManifacName();
	setQuantity();
	setComment();

	cout << "---------------------------------\n";
	cout << "Product Initialized Successfully!\n";
	cout << "---------------------------------\n";
}

void Product::printProduct()const {
	cout << "----------------------\n";
	cout << "Product Information\n";
	cout << "----------------------\n";

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

//setters
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

void Product::updateQuantity(size_t newQuantity) {
	mQuantity = newQuantity;
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
const char* Product::getProdName()const {
	return mProdName;
}

Date Product::getExpireDate()const {
	return mExpireDate;
}

Date Product::getEntryDate()const {
	return mEntryDate;
}

const char* Product::getManifacName()const {
	return mManifacName;
}

unsigned int Product::getQuantity()const {
	return mQuantity;
}

Place Product::getPlace()const {
	return mLocation;
}

const char* Product::getComment()const {
	return mComment;
}

ostream& operator<<(ostream& os, const Product& product) {
	return os;
}

//files
void Product::write(const char* filename,const Product& product) {
	ofstream fout(filename);

	if (fout.is_open()) {
		cout << "Error! File couldn't be opened";
		return;
	}
	else {
		cout << filename << " was opened!";
	}
	
	fout << product.mProdName << product.mExpireDate;
}
