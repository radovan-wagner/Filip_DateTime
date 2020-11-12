#include <iostream>
#include "DateTime_Lib.h"


int main()
{
	DateTime d0("13.10.1998 03:02:01", ".", " ", ":");
	d0.show();
	DateTime d1(10, 9, 2020, 23, 22, 23);
	d1.show();
	//	DateTime d2(10, 9, 2020, 23, 22, 23);
	DateTime d2(11, 11, 2019, 22, 23, 22);
	d2.show();

	system("pause");
	system("cls");

	if (d1 > d2)																// >, <, == funguju
	{
		std::cout << d1 << " is later than " << d2 << std::endl;
	}
	else if (d1 < d2) {
		std::cout << d1 << " is sooner than " << d2 << std::endl;
	}
	else if (d1 == d2)
	{
		std::cout << "They are same." << std::endl;
	}
	else
	{
		std::cout << "Error." << std::endl;
		return -1;
	}

	system("pause");
	system("cls");

	d1.show();
	d2.show();
	std::cout << "\n";

	std::cout << "Test +n: " << d2 + 40 << std::endl;							//+n funguje
	std::cout << "Test -n: " << d1 - 30 << std::endl;							//-n funguje
	std::cout << "Test d1 - d2: " << d1 - d2 << std::endl;						// Pridal som -n funguje
	std::cout << "Test --: " << --d1 << std::endl;								//-- funguje
	std::cout << "Test ++: " << ++d2 << std::endl;								//++ funguje
	std::cout << "Test []: " << d1[0] << std::endl;								//[] funguje

	std::cout << "Difference between 2 days (in sec), d1 - d2 (d1 > d2): " << d1 - d2 << std::endl;
	system("pause");

	return 0;
}
