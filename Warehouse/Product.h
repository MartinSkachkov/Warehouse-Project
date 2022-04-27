#ifndef __PRODUCT_
#define __PRODUCT_
#include "Date.h"
#include "Place.h"
#define MAX_SIZE 1024

class Product {
private:
	char* mProdName;
	Date mExpireDate;
	Date mEntryDate;
	char* mManifacName;
	unsigned int mQuantity;
	Place location;
	char* comment[MAX_SIZE];
public:

};

#endif
