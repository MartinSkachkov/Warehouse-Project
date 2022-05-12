#ifndef __STOCK_
#define __STOCK_
#include "Product.h"
#define SECTIONS 3
#define SHELVES 10
#define SHELF_POS 10

class Stock {
private:
	static Product* mProducts[SECTIONS][SHELVES][SHELF_POS]; //arr of pointers
public:
	//Utils - help-functions
	// -------------------------------------------
	//this function sets every place to empty to indicate there is no product in the beginning
	void setEveryPlaceToEmpty();

	//this function will create an object of type product
	static void createProducts();  // calls initProduct();

	//this function will set a product at an empty space
	static void setProducts(const Product& product);

	//this function will tell the number of repetitions of a product
	int productsWithSameName();

	//save the product to a file
	static void saveToFile();
	// -------------------------------------------
	
	//Main Functions
	//these function will add new product
	static void addProducts(const Product& product);

	//this function will display all details of all products available in the Warehouse
	static void displayProducts();
	
	//this function will remove a product
	static void removeProducts();

	//this function will check if a product is available
	static bool availabilityCheck();

	//clears up the warehouse
	static void clearingUp();

};

#endif
