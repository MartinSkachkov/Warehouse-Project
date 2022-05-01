#include "UniqueID.h"
#include <iostream>
using namespace std;

//set the value of nextID to start from 0
size_t UniqueID::nextID = 0;

//when an object of type UniqueID is created set its id
UniqueID::UniqueID() {
	id = ++nextID;
}

//Copy constr
UniqueID::UniqueID(const UniqueID& original) {
	id = original.id;
}

//Op=
UniqueID& UniqueID::operator=(const UniqueID& original) {
	id = original.id;
	return *this;
}

//getter
size_t UniqueID::getID()const {
	return id;
}