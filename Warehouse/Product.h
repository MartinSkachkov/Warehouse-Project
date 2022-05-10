#ifndef __PRODUCT_
#define __PRODUCT_
#include <fstream>
#include <iostream>
#include "Date.h"
#include "Place.h"
#include "UniqueID.h"
#define MAX_LEN 1024

class Product {
private:
	char* mProdName;
	Date mExpireDate;
	Date mEntryDate;
	char* mManifacName;
	unsigned int mQuantity;
	Place mLocation;
	char mComment[MAX_LEN]; //a comment should be short with a fixed number of characters

	void copyFrom(const Product& source);
	void free();

public:
	Product();
	Product(const Product& source);
	Product& operator=(const Product& source);
	~Product();

	//helpful functions
	void initProduct();
	void printProduct()const;

	//setters
	void setProdName();
	void setManifacName();
	void setQuantity();
	void updateQuantity(size_t newQuantity);
	void setComment();

	//getters
	const char* getProdName()const;
	Date getExpireDate()const;
	Date getEntryDate()const;
	const char* getManifacName()const;
	unsigned int getQuantity()const;
	Place getPlace()const;
	const char* getComment()const;
	
	//op<< - giving errors
	friend ostream& operator<<(ostream& os, const Product& product);

	//file - giving errors
	static void write(const char* fileName, const Product& product);
	static void read(const char* fileName);
}; 

#endif
