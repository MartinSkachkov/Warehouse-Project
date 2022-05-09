#ifndef __DATE_
#define __DATE_
#define MAX_YEAR 9999
#define MIN_YEAR 1900

class Date {
private:
	size_t mYear;
	size_t mMonth;
	size_t mDay;
public:
	//function to initialize the member-data
	void init();

	//functions for checking if the entered date is valid
	bool isLeapYear()const;
	bool isValidDate()const;

	//operators overloaded
	bool operator!=(const Date& other);
	bool operator==(const Date& other);

	//setters
	void setYear();
	void setMonth();
	void setDay();

	//getters
	size_t getYear()const;
	size_t getMonth()const;
	size_t getDay()const;

	//needed for file writing
	friend ostream& operator<<(ostream& os, const Date& date);
	friend istream& operator>>(istream& is, Date& date);
};
#endif