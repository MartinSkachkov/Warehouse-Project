#ifndef __PRODUCT_
#define __PRODUCT_
#include "Date.h"
#include "Place.h"
#define MAX_LEN 1024

class Product {
private:
	char* mProdName;
	Date mExpireDate;
	Date mEntryDate;
	char* mManifacName;
	unsigned int mQuantity;
	Place mLocation;
	char mComment[MAX_LEN];

public:
	Product();
	~Product();

	void initProduct();
	void printProduct()const;

	//setters
	void setProdName();
	void setManifacName();
	void setQuantity();
	void setComment();

	//getters
	const char* getProdName()const;
	const char* getManifacName()const;
	unsigned int getQuantity()const;
	const char* getComment()const;
	Place getPlace()const;
}; 

#endif
