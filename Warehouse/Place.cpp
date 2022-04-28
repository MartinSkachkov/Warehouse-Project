#include "Place.h"
#include <iostream>
using namespace std;

Place::Place() : mSection(0), mShelf(0), mId(0) {}

void Place::initPlace() {
	cout << "Choose section: ";
	cin >> mSection;

	cout << "Choose shelf: ";
	cin >> mShelf;

	cout << "Choose Id: ";
	cin >> mId;
}

size_t Place::getSection()const {
	return mSection;
}

size_t Place::getShelf()const {
	return mShelf;
}

size_t Place::getId()const {
	return mId;
}