#include <iostream>
#include "ring.h"


int main()
{
	ringList ring;
	int select = 0;
	bool work = 1;
	int tmp1 = 0;
	int tmp2 = 0;
	

	while (work)
	{
		system("cls");
		
		ring.printRing();

		printf_s("1 - Add element \n2 - Delete Element \n3 - Move right \n4 - Move left \n5 - Search element \n0 - Exit\n");
		printf_s("Enter your choice: ");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			printf_s("Enter position: ");
			scanf_s("%d", &tmp1);
			printf_s("Enter data: ");
			scanf_s("%d", &tmp2);
			ring.addElement(tmp1, tmp2);
			break;

		case 2:
			printf_s("Enter position: ");
			scanf_s("%d", &tmp1);
			ring.deleteElement(tmp1);
			break;

		case 3:
			ring.moveRight();
			break;

		case 4:
			ring.moveLeft();
			break;

		case 5:
			printf_s("Enter num: ");
			scanf_s("%d", &tmp2);
			ring.searchElement(tmp2);
			system("pause");
			break;

		case 0:
			work = 0;
			break;
		}

	}


	return 0;
}