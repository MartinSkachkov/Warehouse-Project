#ifndef __PLACE_
#define __PLACE_
#include "UniqueID.h"

class Place {
private:
	size_t mSection;
	size_t mShelf;
	size_t mId; //id-�� �������� �� �����������
	UniqueID mUniqueId; //��� ����������� �� product
	//�� �� ������� � �������� id ���������� �� ����������
public:
	Place();

	void initPlace();

	//getters
	size_t getSection()const;
	size_t getShelf()const;
	size_t getId()const;
}; 

#endif 
