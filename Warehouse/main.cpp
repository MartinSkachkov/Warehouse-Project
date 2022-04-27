#include "Date.h"
#include <iostream>
using namespace std;

int main() {
	Date date;
	date.init(date);
	cout << date.getYear() << ' '<< date.getMonth() << ' '<<date.getDay();
}