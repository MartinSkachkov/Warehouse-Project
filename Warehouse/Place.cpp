#include "Place.h"
#include <iostream>
using namespace std;

//Place::Place() : mSection(0), mShelf(0), mId(0) {}

/*void Place::initPlace() {
	cout << "Choose section: ";
	cin >> mSection;

	cout << "Choose shelf: ";
	cin >> mShelf;

	cout << "Choose Id: ";
	cin >> mId;
}*/

//setters
void Place::setEmptyPlace(size_t num) {
	//0 - empty
	//1 - non-empty
	mIsEmptyPlace = num;
}

void Place::setSection(size_t num) {
	mSection = num;
}

void Place::setShelf(size_t num) {
	mShelf = num;
}

//getters
size_t Place::getEmptyPlace()const {
	return mIsEmptyPlace;
}

size_t Place::getSection()const {
	return mSection;
}

size_t Place::getShelf()const {
	return mShelf;
}

size_t Place::getId()const {
	return mUniqueId.getID();
}