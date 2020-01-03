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
	charStrings();
	floatingPoint();
	escapeSequences();
	qualifiers();
	references();
	structure();
	bitFields();
	enumerations();
	unions();
	typedefs();
	voidFunc();
	autoType();
	unambigousNullPointer();
}

void dataTypesPrint(std::string argString)
{
	std::cout << "Data Types Chapter: " << argString << std::endl;
}

void integers()
{
	dataTypesPrint(__FUNCTION__);
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

void floatingPoint()
{
	dataTypesPrint(__FUNCTION__);
	dataTypesPrint("*** Floating Point ***");

	constexpr size_t byte = 8;

    float f;
    double df;
    long double ldf;

    printf("size of float f is %ld bits\n", sizeof(f) * byte);
    printf("size of double float df is %ld bits\n", sizeof(df) * byte);
    printf("size of long double float ldf is %ld bits\n", sizeof(ldf) * byte);

    f = 2e10;
    printf("f : %1.20f \n", f);

    f = 2e20;
    printf("f :  %1.20f\n", f);


}

void charStrings()
{
	dataTypesPrint(__FUNCTION__);
	dataTypesPrint("*** Characters and C Strings ***");

	dataTypesPrint("C String is primitive array of char terminated with a 0");
	dataTypesPrint("C String aka NULL terminated string");

	char cString[] = "C String";
	printf("cString : %s \n", cString);

	// concatenate using ' '
	const char *cStringPtr = "C String " "const char Pointer";
	printf("cString : %s \n", cStringPtr);


	// loop until the last element (which is 0) is reached
	for (int i=0; cStringPtr[i] != 0; i++)
	{
		printf("cStringPtr[%d] : %c \n", i, cStringPtr[i]);
	}

	// loop while character pointer is not NULL
	for (char *charPtr = cString; *charPtr; charPtr++)
	{
		std::cout << "charPtr" << " : " << std::hex << charPtr << std::endl;
		std::cout << "*charPtr" << " : " << std::hex << *charPtr << std::endl;

	}


}

void escapeSequences()
{
	dataTypesPrint(__FUNCTION__);

	dataTypesPrint("*** Esacpe Sequences ***");

	puts(" \"Hello World \" \t");
	puts(" Hello \x40 World \n");

	puts(" Hello Unicode \u03bc \n");

}

class S {
public:
    int static_value() {
        static int x = 7;
        return ++x;
    }
};

int staticIncrement() {
    static int x = 7;
    return ++x;
}

void qualifiers()
{
	dataTypesPrint(__FUNCTION__);
	dataTypesPrint("*** Qualifiers ***");


	int i = 42;
	i = staticIncrement();
	printf("static int x = : %d \n", i);
	i = staticIncrement();
	printf("static int x = : %d \n", i);
	i = staticIncrement();
	printf("static int x = : %d \n", i);

	S a;
	S b;
	S c;
	printf("a.static_value() : %d \n", a.static_value());
	printf("b.static_value() : %d \n", b.static_value());
	printf("c.static_value() : %d \n", c.static_value());

}

int & fRef(int & i)
{
	return ++i;
}

const int & fConstRef(int & i)
{
	return ++i;
}

const int & fConstRefArg(const int & i)
{
	// does not make any sense if you need to modify
	// use pointer instead if possible
	return i;
}

void references()
{
	dataTypesPrint(__FUNCTION__);
	dataTypesPrint("*** References / Alias ***");

	int i = 5;
	int &iR = i;
	iR = 10;
	printf("i is %d \n", i);
	iR = 20;
	printf("i is %d \n", i);

	printf("fRef(i) : %d \n", fRef(i));
	printf("i : %d \n", i);
	printf("fRef(i) : %d \n", fRef(i) = 42);
	printf("i : %d \n", i);

	printf("fConstRef(i) : %d \n", fConstRef(i));
	printf("i : %d \n", i);

	printf("fConstRefArg(i) : %d \n", fConstRefArg(i));
	printf("i : %d \n", i);

}

void structure()
{
	struct Employee {
	    int id;
	    const char * name;
	    const char * role;
	};

	dataTypesPrint(__FUNCTION__);
	dataTypesPrint("*** Structures ***");
    Employee joe = { 42, "Joe", "Boss" };

    printf("%s is the %s and has id %d\n",
           joe.name, joe.role, joe.id);

    Employee * employeePtr = &joe;
    printf("%s is the %s and has id %d\n",
    		employeePtr->name, employeePtr->role, employeePtr->id);

}

void bitFields()
{
	dataTypesPrint(__FUNCTION__);
	dataTypesPrint("*** Bit Fields (packing is not guaranteed) ***");

	struct preferences {
	    bool likesMusic : 1;
	    bool hasHair : 1;
	    bool hasInternet : 1;
	    bool hasDinosaur : 1;
	    unsigned int numberOfChildren : 4;
	};

    struct preferences homer;
    homer.likesMusic = true;
    homer.hasHair = false;
    homer.hasInternet = true;
    homer.hasDinosaur = false;
    homer.numberOfChildren = 3;

    printf("sizeof int: %ld bits\n", sizeof(int) * 8);
    printf("sizeof homer: %ld bits\n", sizeof(homer) * 8);

    if(homer.likesMusic) printf("homer likes music\n");
    if(homer.hasHair) printf("homer has hair\n");
    if(homer.hasInternet) printf("homer has net\n");
    if(homer.hasDinosaur) printf("homer has a dino\n");
    printf("homer has %d children\n", homer.numberOfChildren);


}

enum card_suit : uint8_t { SPD, HRT, DIA, CLB };
enum card_rank : uint8_t { ACE = 1, DEUCE = 2, JACK = 11, QUEEN, KING };

constexpr const char * aceString = "Ace";
constexpr const char * jckString = "Jack";
constexpr const char * queString = "Queen";
constexpr const char * kngString = "King";
constexpr const char * deuString = "Deuce";
constexpr const char * spdString = "Spades";
constexpr const char * hrtString = "Hearts";
constexpr const char * diaString = "Diamonds";
constexpr const char * clbString = "Clubs";

struct card {
    uint8_t rank : 4;
    uint8_t suit : 4;
};

card deck[52] = {
    { ACE, SPD }, { DEUCE, SPD }, { 3, SPD }, { 4, SPD }, { 5, SPD }, { 6, SPD }, { 7, SPD },
    { 8, SPD }, { 9, SPD }, { 10, SPD }, { JACK, SPD }, { QUEEN, SPD }, { KING, SPD },
    { 1, HRT }, { 2, HRT }, { 3, HRT }, { 4, HRT }, { 5, HRT }, { 6, HRT }, { 7, HRT },
    { 8, HRT }, { 9, HRT }, { 10, HRT }, { 11, HRT }, { 12, HRT }, { 13, HRT },
    { 1, DIA }, { 2, DIA }, { 3, DIA }, { 4, DIA }, { 5, DIA }, { 6, DIA }, { 7, DIA },
    { 8, DIA }, { 9, DIA }, { 10, DIA }, { 11, DIA }, { 12, DIA }, { 13, DIA },
    { 1, CLB }, { 2, CLB }, { 3, CLB }, { 4, CLB }, { 5, CLB }, { 6, CLB }, { 7, CLB },
    { 8, CLB }, { 9, CLB }, { 10, CLB }, { 11, CLB }, { 12, CLB }, { 13, CLB }
};

void print_card( const card & c ) {
    if(c.rank > DEUCE && c.rank < JACK) {
        printf("%d of ", c.rank);
    } else {
        switch(c.rank) {
            case ACE:
                printf("%s of ", aceString);
                break;
            case JACK:
                printf("%s of ", jckString);
                break;
            case QUEEN:
                printf("%s of ", queString);
                break;
            case KING:
                printf("%s of ", kngString);
                break;
            case DEUCE:
                printf("%s of ", deuString);
                break;
        }
    }
    switch(c.suit) {
        case SPD:
            puts(spdString);
            break;
        case HRT:
            puts(hrtString);
            break;
        case DIA:
            puts(diaString);
            break;
        case CLB:
            puts(clbString);
            break;
    }
}

void enumerations()
{
	dataTypesPrint(__FUNCTION__);
	dataTypesPrint("*** Enumerations ***");

    long int count = sizeof(deck) / sizeof(card);
    printf("count: %ld cards\n", count);
    for( card c : deck ) {
        print_card(c);
    }
}

void unions()
{
	dataTypesPrint(__FUNCTION__);
	dataTypesPrint("*** Union ***");

	union ipv4 {
	    uint32_t i32;
	    struct {
	        uint8_t a;
	        uint8_t b;
	        uint8_t c;
	        uint8_t d;
	    } octets;
	};

    union ipv4 addr;
    addr.octets = { 192, 168, 73, 42 };
    printf("addr is %d.%d.%d.%d is %08x\n",
           addr.octets.a, addr.octets.b, addr.octets.c, addr.octets.d, addr.i32 );

}

void typedefs()
{
	dataTypesPrint(__FUNCTION__);
	dataTypesPrint("*** typedef ***");

	typedef unsigned char points_t;
	typedef unsigned char rank_t;

	struct score
	{
		points_t p;
		rank_t r;
	};

	dataTypesPrint(__FUNCTION__);
	dataTypesPrint("*** typedef ***");
	score iScore = { 5, 1 };

	printf("score s has %d poins and rank of %d \n", iScore.p, iScore.r);

}

void voidFunc(void)
{
	puts("this is a void func (void)");
}

std::string funcString()
{
	return std::string("This is an STL string");
}

void autoType()
{
	dataTypesPrint(__FUNCTION__);
	dataTypesPrint("*** auto ***");

	auto autoString = funcString();
	printf("autoString : %s \n", autoString.c_str());
	if(typeid(autoString) == typeid(std::string)) puts("autString is an STL string");


    std::vector<int> vi = { 1, 2, 3, 4, 5 };
    for(std::vector<int>::iterator it = vi.begin(); it != vi.end(); ++it) {
        printf("int is %d\n", *it);
    }

    for(auto iter = vi.begin(); iter != vi.end(); ++iter) {
        printf("auto iteraraor : int is %d\n", *iter);
    }

}

void overldFunc( int i ) {
    printf("the int is %d\n", i);
}

void overldFunc( const char * s ) {
    printf("the pointer is %p\n", s);
}

void unambigousNullPointer()
{
	overldFunc(8);
	overldFunc("test");
	// overldFunc(NULL);
	overldFunc(nullptr);

}
