#ifndef __PLACE_
#define __PLACE_
#include "UniqueID.h"

class Place {
private:
	size_t mSection;
	size_t mShelf;
	size_t mShelfPos;
	UniqueID mUniqueId; //when a product is created the program initializes it with a unique id
public:
	//setters
	void setSection(size_t num);
	void setShelf(size_t num);
	void setShelfPos(size_t num);

	//getters
	size_t getSection()const;
	size_t getShelf()const;
	size_t getShelfPos()const;
	size_t getId()const;
}; 

#endif 
