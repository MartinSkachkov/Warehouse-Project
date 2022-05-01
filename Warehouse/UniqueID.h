#ifndef __UNIQUE_ID_
#define __UNIQUE_ID_

//UniqueID helps us to create an unique serial number for each product
class UniqueID {
private:
	static size_t nextID;
public:
	size_t id;
	UniqueID();
	UniqueID(const UniqueID& original);
	UniqueID& operator=(const UniqueID& original);

	//getter
	size_t getID()const;
};

#endif

