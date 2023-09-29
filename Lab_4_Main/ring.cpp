#include "ring.h"

void ringList::addElement(int& pos, int& data)
{
	if (isRingEmpty())
	{
		current = new element;
		current->next = current;
		current->prev = current;
		current->data = data;
		return;
	}

	element* el = current->prev;
	int i = 0;

	while (i < pos && el->next != current->prev)
	{
		i++;
		el = el->next;
	}

	element* el2 = new element;
	el2->data = data;
	el2->prev = el;
	el2->next = el->next;
	el->next = el2;
	el2->next->prev = el2;

	if (i == 0)
		current = el2;
}

void ringList::deleteElement(int& pos)
{
	if (isRingEmpty())
		return;

	if (current == current->next)
	{
		current->data = 0;
		current->next = current->prev = 0;
		delete current;
		current = 0;
		return;
	}

	element* el = current;
	int i = 0;

	while (i < pos && el->next != current)
	{
		i++;
		el = el->next;
	}

	el->prev->next = el->next;
	el->next->prev = el->prev;
	if (el == current)
		current = el->next;
	delete el;

}

void ringList::moveRight()
{
	current = current->prev;
}

void ringList::moveLeft()
{
	current = current->next;

}

void ringList::searchElement(int& num)
{
	if (isRingEmpty())
		return;


	int i = 0;
	element* el = current->next;

	if (current->data == num)
		printf_s("%d ", i);

	while (el != current)
	{
		++i;
		if(el->data == num)
			printf_s("%d ", i);

		el = el->next;
	}

	printf_s("\n");

}



ringList::~ringList()
{
	element* el = current->next;

	while (el != current)
	{
		el = el->next;
		delete el->prev;
	}

	delete current;
}

void ringList::printRing()
{
	if (isRingEmpty())
		return;

	element* el = current->next;

	printf_s("<->%d<->", current->data);

	while (el != current)
	{
		printf_s("%d<->", el->data);
		el = el->next;
	}

	printf_s("\n");
}

bool ringList::isRingEmpty()
{
	return !current;
}




