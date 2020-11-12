// DateTime_Lib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DateTime_Lib.h"

// int main()
// {
	// std::cout << "Hello World!\n";
// }

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

	std::cout << "Test +n: " << d2 + 40 << std::endl;							//-n funguje
	std::cout << "Test -n: " << d1 - 30 << std::endl;							//+n funguje
	std::cout << "Test --: " << --d1 << std::endl;								//-- funguje
	std::cout << "Test ++: " << ++d2 << std::endl;								//++ funguje
	std::cout << "Test []: " << d1[0] << std::endl;								//[] funguje

	std::cout << "Difference between 2 days (in sec), d1 - d2 (d1 > d2): " << d1 - d2 << std::endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

