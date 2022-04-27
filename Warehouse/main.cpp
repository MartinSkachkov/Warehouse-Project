#include "Date.h"
#include <iostream>
using namespace std;

int main() {
	Date date;
	date.init();
	cout << date.getYear() << ' '<< date.getMonth() << ' '<<date.getDay();
}