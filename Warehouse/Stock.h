#ifndef __STOCK_
#define __STOCK_
#include "Product.h"

class Stock {
private:
	Product** mProducts;
	size_t mSize;
	size_t mCapacity;

	void copy(const Stock& source);
	void resize(size_t newCapacity);
	void erase();
public:
	Stock();

	void setProducts(const Product);
	
};

#endif
