#include "Date.h"
#include <iostream>
using namespace std;

//function to initialize the member-data
void Date::init() {
	do {
		setYear();
		setMonth();
		setDay();
		if (isValidDate()) {
			cout << "Valid Date! Saved successfully\n";
		}
		else {
			cout << "Invalid Date! Enter again!\n";
		}
	} while (!isValidDate());
}

//functions for checking if the entered date is valid
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

//operators overloaded
bool Date::operator!=(const Date& other) {
	if (this->mYear != other.mYear && this->mMonth != other.mMonth && this->mDay != other.mDay) {
		return true; //dates are different
	}
	return false; //dates are not different
}

bool Date::operator==(const Date& other) {
	if (this->mYear == other.mYear && this->mMonth == other.mMonth && this->mDay == other.mDay) {
		return true; //dates are not different
	}
	return false; //dates are different
}


//setters
void Date::setYear() {
	cout << "Year: ";
	cin >> mYear;
}

void Date::setMonth() {
	cout << "Month: ";
	cin >> mMonth;
}

void Date::setDay() {
	cout << "Day: ";
	cin >> mDay;
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

//needed for file writing(the second parameter passed to the function is left because this could be helpful when printing the date but should improve)
ostream& operator<<(ostream& os, const Date& date) {
	return os;
}

istream& operator>>(istream& is, Date& date) {
	return is;
}
