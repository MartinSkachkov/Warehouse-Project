#ifndef __PLACE_
#define __PLACE_
#include "UniqueID.h"

class Place {
private:
	size_t mIsEmptyPlace; //a help-variable that will tell us if the current place is empty or not
	size_t mSection;
	size_t mShelf;
	UniqueID mUniqueId; //when a product is created the program initializes it with a unique id
public:
	//void initPlace();

	//setters
	void setEmptyPlace(size_t num); //needed for void setEveryPlaceToZero(); function
	void setSection(size_t num);
	void setShelf(size_t num);

	//getters
	size_t getEmptyPlace()const; //a help-function that will tell us if the current place is empty or not
	size_t getSection()const;
	size_t getShelf()const;
	size_t getId()const;
}; 

#endif 
