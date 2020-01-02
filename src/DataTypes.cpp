/*
 * DataTypes.cpp
 *
 *  Created on: 2 Jan 2020
 *      Author: dasco
 */

#include "DataTypes.h"

void dataTypesMain()
{
	dataTypesPrint("*** Main ***");
	integers();
}

void dataTypesPrint(std::string argString)
{
	std::cout << "Data Types Chapter: " << argString << std::endl;
}

void integers()
{
	dataTypesPrint("*** Integers ***");

	constexpr size_t byte = 8;
	printf("sizeof char is %ld bits\n", sizeof(char) * byte);
	printf("sizeof short int is %ld bits\n", sizeof(short int) * byte);
	printf("sizeof short is %ld bits\n", sizeof(short) * byte);

	printf("sizeof int is %ld bits\n", sizeof(int) * byte);
	printf("sizeof long int is %ld bits\n", sizeof(long int) * byte);
	printf("sizeof long is %ld bits\n", sizeof(long) * byte);

	printf("sizeof long long int is %ld bits\n", sizeof(long long int) * byte);

	printf("sizeof int8_t is %ld bits\n", sizeof(int8_t) * byte);
	printf("sizeof int16_t is %ld bits\n", sizeof(int16_t) * byte);
	printf("sizeof int32_t is %ld bits\n", sizeof(int32_t) * byte);
	printf("sizeof int64_t is %ld bits\n", sizeof(int64_t) * byte);
	printf("sizeof uint8_t is %ld bits\n", sizeof(uint8_t) * byte);
	printf("sizeof uint16_t is %ld bits\n", sizeof(uint16_t) * byte);
	printf("sizeof uint32_t is %ld bits\n", sizeof(uint32_t) * byte);
	printf("sizeof uint64_t is %ld bits\n", sizeof(uint64_t) * byte);

}
