#ifndef __STOCK_
#define __STOCK_
#include "Product.h"

class Stock {
private:
	Product mProducts[3][10];
	/*size_t mSize;
	size_t mCapacity;

	void copy(const Stock& source);
	void resize(size_t newCapacity);
	void erase();*/
public:
	Stock();
	//Utils
	void setProdNumToZero();

	//this function will add new product
	void createProducts();  // calls initProduct()

	//this function will display all details of all products available in the Warehouse
	void displayProducts()const;
	
	//this function will remove a product
	void removeProducts();

	//this function will check if a product is available
	bool availabilityCheck();

	//clears up the warehouse
	void clearingUp();

};

#endif
