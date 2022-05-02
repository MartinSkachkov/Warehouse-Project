#ifndef __STOCK_
#define __STOCK_
#include "Product.h"
#define SECTIONS 3
#define SHELVES 10

class Stock {
private:
	Product mProducts[SECTIONS][SHELVES];
	/*size_t mSize;
	size_t mCapacity;

	void copy(const Stock& source);
	void resize(size_t newCapacity);
	void erase();*/
public:
	//Utils
	// -------------------------------------------
	//this function sets every place to empty to indicate there is no product in the beginning
	void setEveryPlaceToEmpty();

	//this function will check if there is a product with the same name
	bool productWithSameName(const Product& other)const;

	//this function will count products with same name
	size_t countProductWithSameName(const Product& other)const;

	// -------------------------------------------

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

	//friend class that should have an access to the methods of this class
	friend WarehouseService;
};

#endif
