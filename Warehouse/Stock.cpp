#include "Stock.h"
#include <iostream>
using namespace std;

void Stock::copy(const Stock& source) {
	mSize = source.mSize;
	mCapacity = source.mCapacity;
	mProducts = new Product* [mCapacity];

	for (size_t i = 0; i < mSize; i++){
		mProducts[i] = new Product(*(source.mProducts[i])); //deep copy
	}
}

void Stock::erase() {
	for (size_t i = 0; i < mSize; i++){
		delete mProducts[i];
	}
	delete[] mProducts;
}

//void Stock::resize

//Stock::Stock() : mProducts(nullptr), mSize(0), mCapacity(0) {}