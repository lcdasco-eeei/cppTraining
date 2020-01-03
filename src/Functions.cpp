/*
 * Functions.cpp
 *
 *  Created on: 3 Jan 2020
 *      Author: dasco
 */


#include "Functions.h"

void functionsMain()
{
	functionsPrint("*** Main ***");
	overview();
}

void functionsPrint(std::string argString)
{
	std::cout << "Functions Chapter: " << argString << std::endl;
}

void callByValue(int a)
{
	a++;
}

void callByRefPtrArg(int *intPtr)
{
	++(*intPtr);
}

void callByRefRefArg(int &intRef)
{
	++intRef;
}

void overview()
{
	int i = 7;
	callByValue(i);
	printf("i : %d \n", i);
	callByRefPtrArg(&i);
	printf("i : %d \n", i);
	callByRefRefArg(i);
	printf("i : %d \n", i);

}
