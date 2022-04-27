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
	Date();

	void init();
	bool isLeapYear()const;
	bool isValidDate()const;

	//getters
	size_t getYear()const;
	size_t getMonth()const;
	size_t getDay()const;
};

#endif