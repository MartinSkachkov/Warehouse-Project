#include "Stock.h"
#include <iostream>
using namespace std;

/*void Stock::copy(const Stock& source) {
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
}*/

//void Stock::resize

Stock::Stock() {
	
}

void Stock::setProdNumToZero() {
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			mProducts[i][j].getPlace().() = 0;
		}
	}
}

void Stock::createProducts() {
	Product newProduct;//constr for newPr
	for (size_t i = 0; i < 3; i++){
		for (size_t j = 0; j < 10; j++){
			if(mProducts[i][j].getPlace().getId()!=0){
			mProducts[i][j](newProduct);//copy constr
			}
			else
			{
				cout << "no available space";
			}
		}
	}
}

//this function will display all details of all products available in the Warehouse
void Stock::displayProducts()const {
	for (size_t i = 0; i < 3; i++){
		for (size_t j = 0; j < 10; j++){
			mProducts[i][j].printProduct();
			
		}
	}
}