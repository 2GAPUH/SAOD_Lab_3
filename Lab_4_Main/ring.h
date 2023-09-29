#pragma once
#include <iostream>



class element
{
public:
	int data = 0;
	element* next = NULL;
	element* prev = NULL;
};

class ringList
{
public:
	element* current;
	~ringList();
	void addElement(int& pos, int& data);
	void deleteElement(int& pos);
	void moveRight();
	void moveLeft();
	void searchElement(int& num);
	void printRing();
	bool isRingEmpty();
};

