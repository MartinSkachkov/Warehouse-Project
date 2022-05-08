#include "Date.h"
#include "Product.h"
#include "Stock.h"
#include "Service.h"
#include <iostream>
using namespace std;

int main() {

	size_t option, flag = 0;
	
	// Menu
	// diaply all options available in Warehouse
	while (1){
		cout << "\n\tPress 1 to DISPLAY COMPLETE STOCK";
		cout << "\n\tPress 2 to INSERT NEW PRODUCT";
		cout << "\n\tPress 3 to REMOVE PRODUCT";
		cout << "\n\tPress 4 to AVAILABILITY CHECK";
		cout << "\n\tPress 5 to CLEARING UP";
		cout << "\n\n\tOption: ";
		//input user's choice and then call respective fucntion using switch cases
		cin >> option;
		switch (option) {
		case 1:
			Stock::createProducts();
			break;

		case 2:
			Stock::displayProducts();
			break;

		case 3:
			Stock::removeProducts();
			break;

		case 4:
			Stock::availabilityCheck();
			break;

		case 5: 
			Stock::clearingUp();
			break;

		case 6:
			flag = 1;
			break;
		}
			if (flag == 1)
			{
				break;
			}
	}
	
	return 0;
}