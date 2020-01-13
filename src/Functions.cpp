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
	passingValues();
	funcStorageAutoStatic();
	returnType();
	funcPtr();
	arrayFuncPtr();
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
	functionsPrint(__FUNCTION__);

	int i = 7;
	callByValue(i);
	printf("i : %d \n", i);
	callByRefPtrArg(&i);
	printf("i : %d \n", i);
	callByRefRefArg(i);
	printf("i : %d \n", i);

}

// void passByRef(const int & i)
void passByRef(int & i)
{
	i = 73;
	printf("the value of i in passByRef %d \n", i);
}

void passByPtr(int *i)
{
	*i = 73;
	printf("the value of i in passByPtr %d \n", *i);
}

void passByRefString(const std::string & stringRef)
{
	printf("pass by ref %s \n", stringRef.c_str());
}

void passingValues()
{
	functionsPrint(__FUNCTION__);

	int i = 42;
	puts("this is main()");
	passByRef(i);
	printf("after passByRef() is is %d \n", i);
	passByPtr(&i);

	std::string s = "this is a string";
	passByRefString(s);

}

void autoStorage()
{
	int i = 5;
	printf("autoStorage i = %d \n", ++i);
}

void staticStorage()
{
	static int i = 5;
	printf("staticStorage i = %d \n", ++i);
}

void funcStorageAutoStatic()
{
	functionsPrint(__FUNCTION__);
	autoStorage();
	autoStorage();
	autoStorage();
	staticStorage();
	staticStorage();
	staticStorage();
}

int returnValue(int i)
{
	return i*2;
}

const std::string & returnRef()
{
	 const static std::string s = "this is returnRef()";
	 return s;
}

void returnType()
{
	functionsPrint(__FUNCTION__);

	int x = 12;
	printf("returnValue() = %d \n", returnValue(x));

	const std::string & str = returnRef();
	printf(" returnRef() : %s \n", str.c_str());

}


void funcPtrSample()
{
	printf("This is funcPtrSample() \n");
}

void funcPtr()
{
	functionsPrint(__FUNCTION__);

	void (*funcPtr)() = funcPtrSample;
	puts("C++ Stlye : funcPtr()");
	funcPtr();
	puts("C Syle : (*funcPtr)()");
	(*funcPtr)();

}

const char * prompt();
int jump( const char * );

void fa() { puts("this is fa()"); }
void fb() { puts("this is fb()"); }
void fc() { puts("this is fc()"); }
void fd() { puts("this is fd()"); }
void fe() { puts("this is fe()"); }

void (*funcs[])() = { fa, fb, fc, fd, fe };

const char * prompt() {
    puts("Choose an option:");
    puts("1. Function fa()");
    puts("2. Function fb()");
    puts("3. Function fc()");
    puts("4. Function fd()");
    puts("5. Function fe()");
    puts("Q. Quit.");
    printf(">> ");
    fflush(stdout);                 // flush after prompt

    const int buffsz = 16;          // constant for buffer size
    static char response[buffsz];   // static storage for response buffer
    fgets(response, buffsz, stdin); // get response from console

    return response;
}

int jump( const char * rs ) {
    char code = rs[0];
    if(code == 'q' || code == 'Q') return 0;

    // get the length of the funcs array
    int func_length = sizeof(funcs) / sizeof(funcs[0]);

    int i = (int) code - '0';   // convert ASCII numeral to int
    if( i < 1 || i > func_length ) {
        puts("invalid choice");
        return 1;
    } else {
        funcs[i - 1]();         // array is zero-based
        return 1;
    }
}

void arrayFuncPtr()
{
	functionsPrint(__FUNCTION__);
    while(jump(prompt())) ;
    puts("\nDone.");
}

