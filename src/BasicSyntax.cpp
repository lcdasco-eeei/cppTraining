/*
 * BasicSyntax.cpp
 *
 *  Created on: 2 Jan 2020
 *      Author: dasco
 */

#include "BasicSyntax.h"

void basicMain()
{
	basicPrint("*** Main ***");
	ptrsRef();
	primitiveArray();
	primitiveStrings();
	conditional();
	switchCase();
	whileLoop();
	forLoop();
}

void basicPrint(std::string argString)
{
	std::cout << "Basics Chapter: " << argString << std::endl;
}

void ptrsRef()
{
	basicPrint("*** Pointers and References ***");
	int x = 7;

	// y contains an address because it is declared as a reference
	int &y = x;
	int *intPtr = &x;
	printf("The value of x is %d\n", x);
	printf("The value of y is %d\n", y);
	std::cout << "The value of &x (address of x) is " << std::hex << &x << std::endl;
	std::cout << "The value of intPtr (address pointed by intPtr) is " << std::hex << intPtr << std::endl;
	printf("The value of *intPtr (content of address pointed by intPtr) is %d\n", *intPtr);

	basicPrint("y=100");
	// reference does not use the *, to de-reference a reference
	y = 100;
	printf("The value of x is %d\n", x);
	printf("The value of y is %d\n", y);
	std::cout << "The value of &x (address of x) is " << std::hex << &x << std::endl;
	std::cout << "The value of intPtr (address pointed by intPtr) is " << std::hex << intPtr << std::endl;
	printf("The value of *intPtr (content of address pointed by intPtr) is %d\n", *intPtr);

	basicPrint("Unlike pointers, references cannot be re-assigned.");
	int z = 200;
	intPtr = &z;
	basicPrint("z=200, intPtr=&z");

	printf("The value of x is %d\n", x);
	printf("The value of y is %d\n", y);
	std::cout << "The value of &x (address of x) is " << std::hex << &x << std::endl;
	std::cout << "The value of &z (address of z) is " << std::hex << &z << std::endl;
	std::cout << "The value of intPtr (address pointed by intPtr) is " << std::hex << intPtr << std::endl;
	printf("The value of *intPtr (content of address pointed by intPtr) is %d\n", *intPtr);
}


void primitiveArray()
{
	basicPrint("*** Primitive Arrays ***");
	int intArray[5] = {1, 2, 3, 4, 5 };
	int *intArrayPtr = intArray;
	std::cout << "intArrayPtr " << std::hex << intArrayPtr << std::endl;
	std::cout << "intArray " << std::hex << intArray << std::endl;
	std::cout << "*intArrayPtr " << std::hex << *intArrayPtr << std::endl;
	std::cout << "*intArray " << std::hex << *intArray << std::endl;
	std::cout << "intArrayPtr[0] " << std::hex << intArrayPtr[0] << std::endl;
	std::cout << "intArray[0] " << std::hex << intArray[0] << std::endl;
	std::cout << "intArrayPtr+1 " << std::hex << intArrayPtr+1 << std::endl;
	std::cout << "intArray+1 " << std::hex << intArray+1 << std::endl;
	std::cout << "intArrayPtr[1] " << std::hex << intArrayPtr[1] << std::endl;
	std::cout << "intArray[1] " << std::hex << intArray[1] << std::endl;
	std::cout << "*(intArrayPtr+1) " << std::hex << *(intArrayPtr+1) << std::endl;
	std::cout << "*(intArray+1) " << std::hex << *(intArray+1) << std::endl;
}

void primitiveStrings()
{
	basicPrint("*** Primitive Strings aka C Strings ***");
	basicPrint("C String is primitive array of char terminated with a 0");
	basicPrint("C String aka NULL terminated string");

	char cString[] = "C String";
	printf("cString : %s \n", cString);

	char charArray[] = {'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', 0};
	printf("charArray : %s \n", charArray);

	// loop until the last element (which is 0) is reached
	for (int i=0; charArray[i] != 0; i++)
	{
		printf("charArray[%d] : %c \n", i, charArray[i]);
	}

	// loop while character pointer is not NULL
	for (char *charPtr = cString; *charPtr; charPtr++)
	{
		std::cout << "charPtr" << " : " << std::hex << charPtr << std::endl;
		std::cout << "*charPtr" << " : " << std::hex << *charPtr << std::endl;

	}

	// ranged based for loop
	for(char c : charArray)
	{
		printf("c : %c \n", c);
	}
}

void conditional()
{
	basicPrint("*** Conditionals ***");

	int x = 43;
	int y = 55;

	std::cout << std::dec << "(x>y) " << (x>y) << std::endl;

	if (x > y)
	{
		std::cout << std::dec << x << " is greater than " << y << std::endl;
	}
	else
	{
		std::cout << std::dec << x << " is not greater than " << y << std::endl;
	}

	printf("x > y ? x : y \n");
	printf("The greater value is %d \n", x > y ? x : y);

}

void switchCase()
{
	basicPrint("*** Switch Case ***");


	const int iONE = 1;
	const int iTWO = 2;
	const int iTHREE = 3;
	const int iFOUR = 4;

	int x = 3;

	switch(x)
	{
		case iONE:
		{
			puts("one");
			break;
		}
		case iTWO:
		{
			puts("two");
			break;
		}
		case iTHREE:
		{
			puts("three");
			break;
		}
		case iFOUR:
		{
			puts("four");
			break;
		}
		default :
		{
			puts("default");
			break;
		}
	}
}

void whileLoop()
{
	basicPrint("*** While Loop ***");
	int intArray[5] = {1, 2, 3, 4, 5 };

	int idx = 0;
	while (idx < 5)
	{
		if (idx == 2)
		{
			idx++;
			continue;
		}
		printf("intArray[%d] : %d \n", idx, intArray[idx]);
		idx++;
	}

	idx = 3;

	basicPrint("*** Do While Loop ***");
	do {
		printf("intArray[%d] : %d \n", idx, intArray[idx]);
		idx++;
	} while(idx < 5);

}


void forLoop()
{
	basicPrint("*** For Loop ***");

	char cString[] = "abcdefg";
	printf("cString : %s \n", cString);


	// loop until the last element (which is 0) is reached
	for (int i=0; cString[i] != 0; i++)
	{
		printf("cString[%d] : %c \n", i, cString[i]);
	}

	// loop while character pointer is not NULL
	for (char *charPtr = cString; *charPtr; charPtr++)
	{
		std::cout << "charPtr" << " : " << std::hex << charPtr << std::endl;
		std::cout << "*charPtr" << " : " << std::hex << *charPtr << std::endl;

	}

	// ranged based for loop
	basicPrint("*** Range Based For Loop ***");

	int intArray[] = {2, 4, 6, 8, 10};
	for (int iter : intArray)
	{
		printf("iter : %d \n", iter);
	}

	for(char c : "my string")
	{
		if (c == 0) break; // to prevent printing 0 at the end of C String
		printf("c : %c \n", c);
	}
}

