#include "Place.h"
#include <iostream>
using namespace std;

//setters
void Place::setSection(size_t num) {
	mSection = num;
}

void Place::setShelf(size_t num) {
	mShelf = num;
}

void Place::setShelfPos(size_t num) {
	mShelfPos = num;
}

//getters
size_t Place::getSection()const {
	return mSection;
}

size_t Place::getShelf()const {
	return mShelf;
}

size_t Place::getShelfPos()const {
	return mShelfPos;
}

size_t Place::getId()const {
	return mUniqueId.getID();
}

//operator for the stream
ostream& operator<<(ostream& os, const Place& place) {
	os << "Section: " << place.getSection() << endl <<
		"Shelf: " << place.getShelf() << endl <<
		"Shelf position: " << place.getShelfPos() << endl <<
		"ID: " << place.getId() << endl;
}