/*
 * CommonOperators.cpp
 *
 *  Created on: 3 Jan 2020
 *      Author: dasco
 */

#include "Operators.h"

void operatorsMain()
{
	operatorsPrint("*** Main ***");
	common();
	incDec();
	relational();
	logical();
	bitwise();
	ternary();
	(dynamicMemory()) ? puts("failed \n") : puts("passed\n");
	castFunc();
	sizeofFunc();
	typeidFunc();
}

void operatorsPrint(std::string argString)
{
	std::cout << "Common Operators Chapter: " << argString << std::endl;
}

void common()
{
	operatorsPrint(__FUNCTION__);
	operatorsPrint("*** Common Operators ***");

	int x = 47;
	int y = 5;

	printf(" %d + %d = %d \n", x, y, x + y);
	printf(" %d - %d = %d \n", x, y, x - y);
	printf(" %d / %d = %d \n", x, y, x / y);
	printf(" %d %% %d = %d \n", x, y, x % y);

	// x is only evaluated once compared to x = x + y
	// no temporary object when compound assignment is used
	printf(" x = %d, y = %d \n", x, y);
	x += y;
	printf(" x = %d, after x+=y \n", x);

	printf(" x = %d, y = %d \n", x, y);
	x -= y;
	printf(" x = %d, after x-=y \n", x);

	printf(" x = %d, y = %d \n", x, y);
	x *= y;
	printf(" x = %d, after x*=y \n", x);
}

void printp(char *p) {
    printf("pointer is %p, value is %d\n", p, *p);
}

void incDec()
{
	operatorsPrint(__FUNCTION__);
	operatorsPrint("*** Increment and Decrement Operators ***");

	int i = 0;
	printf("i is initialized to %d \n", ++i);

	operatorsPrint("Prefix Version, Evaluate First (more efficient)");
	printf("i while ++i is %d \n", ++i);
	printf("i while ++i is %d \n", ++i);
	printf("i while ++i is %d \n", ++i);

	operatorsPrint("Suffix Version, Evaluate After (requires a copy)");
	printf("i while i++ is %d \n", i++);
	printf("i while i++ is %d \n", i++);
	printf("i while i++ is %d \n", i++);

    char arr[5] = { 1, 2, 3, 4, 5 };
    char *p = arr;
    printp(p++);
    printp(p++);
    printp(p++);

    p = arr;
    printp(++p);
    printp(++p);
    printp(++p);

}

void relational()
{
	operatorsPrint(__FUNCTION__);
	operatorsPrint("*** Relational or Comparison Operators ***");
	int x =5;
	int y = 25;
	printf(" x = %d, y = %d \n", x, y);
	printf("(x==y) is %s \n", (x == y) ? "true" : "false");
	printf("(x>=y) is %s \n", (x >= y) ? "true" : "false");
	printf("(x<=y) is %s \n", (x <= y) ? "true" : "false");

}

void logical()
{
	operatorsPrint(__FUNCTION__);
	operatorsPrint("*** Logical Operators ***");
	bool x = true;
	bool y = false;

	printf("(x) is %s \n", (x) ? "true" : "false");
	printf("(y) is %s \n", (y) ? "true" : "false");
	printf("(x&&y) is %s \n", (x && y) ? "true" : "false");
	printf("(x||y) is %s \n", (x || y) ? "true" : "false");

	printf("(!x) is %s \n", (!x) ? "true" : "false");
	printf("(!y) is %s \n", (!y) ? "true" : "false");
	printf("!(x&&y) is %s \n", !(x && y) ? "true" : "false");
	printf("!(x||y) is %s \n", !(x || y) ? "true" : "false");
}


// unsigned 8-bit to string
const char * u8_to_cstr(const uint8_t & x) {
    static char buf[sizeof(x) * 8 + 1];
    for(char & c : buf) c = 0; // reset buffer
    char * bp = buf;
    for(uint8_t bitmask = 0b10000000; bitmask; bitmask >>= 1) {
        *(bp++) = x & bitmask ? '1' : '0';
    }
    return buf;
}

void bitwise()
{
	operatorsPrint(__FUNCTION__);
	operatorsPrint("*** Bitwise Operators ***");

    uint8_t x = 7;
    uint8_t y = 10;

    printf("    x is %s\n", u8_to_cstr(x));
    printf(" x>>1 is %s\n", u8_to_cstr(x>>1));
    printf(" x<<1 is %s\n", u8_to_cstr(x<<1));
    printf("   ~x is %s\n", u8_to_cstr(~x));
    printf("~x>>1 is %s\n", u8_to_cstr(~x>>1));
    printf("~x<<1 is %s\n", u8_to_cstr(~x<<1));


    printf(" y is %s\n", u8_to_cstr(y));
    printf("~y is %s\n", u8_to_cstr(~y));


    printf("x | y %s\n", u8_to_cstr(x | y));
    printf("x & y %s\n", u8_to_cstr(x & y));
    printf("x ^ y %s\n", u8_to_cstr(x ^ y));

}

void ternary()
{
	operatorsPrint(__FUNCTION__);
	operatorsPrint("*** Ternary Conditional Operator ***");
	bool x = true;
	bool y = false;

	printf("(x) is %s \n", (x) ? "true" : "false");
	printf("(y) is %s \n", (y) ? "true" : "false");

}

int dynamicMemory()
{
	operatorsPrint(__FUNCTION__);
	operatorsPrint("*** Dynamic Memory Operator (new and delete) ***");

	constexpr size_t count = 1024;
	// constexpr size_t count = 1024000000000000;

    printf("allocate space for %lu long int at *ip with new\n", count);

    // allocate array
    long int * ip;

    try {
        ip = new long int [count];
    } catch (std::bad_alloc & ba) {
        fprintf(stderr, "Cannot allocate memory (%s)\n", ba.what());
        return 1;
    }

    // initialize array
    for(unsigned long int i = 0; i < count; ++i ) {
        ip[i] = i;
    }

    // print array
    for(unsigned long int i = 0; i < count; ++i ) {
        printf("%ld ", ip[i]);
    }
    puts("");

    // deallocate array
    delete [] ip;
    puts("space at *ip deleted");

    return 0;

}

void castFunc()
{
	operatorsPrint(__FUNCTION__);
	operatorsPrint("*** cast Function ***");

	int x =5;
	long long int y;
	y = x;

	printf("x = %d \n", x);
	printf("y = %lld \n", y);

	x = int(y);
	printf("x = %d \n", x);
	printf("y = %lld \n", y);

}

void sizeofFunc()
{
	operatorsPrint(__FUNCTION__);
	operatorsPrint("*** sizeof Function ***");

	int x = 5;
	size_t y = sizeof x;
	printf("sizeof(x) is %zd \n", y);

	printf("sizeof(int) is %zd \n", sizeof(int));

	struct X
	{
		int a;
		int b;
		char c;
		char d;
		long long int e;
		long long int f;
	};

	printf("sizeof(int) is %zd \n", sizeof(X));

}

void typeidFunc()
{
	operatorsPrint(__FUNCTION__);
	operatorsPrint("*** typeid Function ***");

	struct A { int x; };
	struct B { int x; };

	A a1;
	B b1;

	(typeid(a1) == typeid(A)) ? puts("same type") : puts("different type");
	(typeid(a1) == typeid(b1)) ? puts("same type") : puts("different type");

	printf("typename of int is %s\n", typeid(int).name());
	printf("typename of std::string is %s\n", typeid(std::string).name());
	printf("typename of a1 is %s\n", typeid(a1).name());
	printf("typename of b1 is %s\n", typeid(b1).name());
}

