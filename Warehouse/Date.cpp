#include "Date.h"
#include <iostream>
using namespace std;

Date::Date() : mYear(0), mMonth(0), mDay(0) {}

void Date::init() {
	do {
		cout << "Year: ";
		cin >> mYear;
		cout << "Month: ";
		cin >> mMonth;
		cout << "Day: ";
		cin >> mDay;
		if (isValidDate()) {
			cout << "Valid Date!\n";
		}
		else {
			cout << "Invalid Date! Enter again!\n";
		}
	} while (!isValidDate());
}

bool Date::isLeapYear()const {
	//needed for the isValidDate function
	return((mYear % 4 == 0) && (mYear % 100 != 0) || (mYear % 400 == 0));
}

bool Date::isValidDate()const {
	//standart checks
	if (mYear > MAX_YEAR || mYear < MIN_YEAR) return false;
	if (mMonth < 1 || mMonth > 12) return false;
	if (mDay < 1 || mDay > 31) return false;

	//leap year case
	if (mMonth == 2) {
		if (isLeapYear()) {
			return (mDay <= 29);
		}
		else {
			return (mDay <= 28);
		}
	}

	//case April, June, September, November - 30 days
	if (mMonth == 4 || mMonth == 6 || mMonth == 9 || mMonth == 11) {
		return (mDay <= 30);
	}
	return true;
}

//getters
size_t Date::getYear()const {
	return mYear;
}

size_t Date::getMonth()const {
	return mMonth;
}

size_t Date::getDay()const {
	return mDay;
}