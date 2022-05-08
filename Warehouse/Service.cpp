#include "Service.h"
#include "Stock.h"
#include "Product.h"
#include <iostream>

void WarehouseService::createStock() {
	Stock::addProducts(const Product& product);
}

void WarehouseService::displayStock() {
	Stock::displayProducts();
}