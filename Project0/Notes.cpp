#include "Notes.h"
#include <iostream>
#include <algorithm>
#include <vector>

// Non-local static object
const int Notes::version;
const float Notes::floatVersion = 0.01F;

// Local static object
TempNote& Notes::getTempNote() {
	static TempNote tempNote = TempNote();
	return tempNote;
}



void Notes::Show() {
	// C++ Terminologies
	// = Declaration				- tells the compilers about the name and type of something
	// = Signature					- the parameter and return types of a function declaration
	// = Definition					- the details a declaration omits, 
	//								- for an object, the definition is here compilers set aside memory for the object
	//								- for a function or a function template, the definition provides the code body
	//								- for a class or a class template, the definition lists the members of the class or templates
	// = Initialization				- process of giving an object its first value. performed by constructors
	// = Default constructor		- one that can be called without any arguments, no parameters or has a default value for every parameter
	// = Explicit constructor		- constructors are declared explicit to prevent compilers from performing unexpected (often unintended) type conversions
	// = Copy constructor			- used to initialize an object with a different object of the same type
	// = Copy assignment operator	- used to copy the value from one object to another of the same type
	// = Function objects			- objects that acts like functions. they come from classes that overload operator(), the function call operator.

	/* References:
		Explicit constructors:		http://en.cppreference.com/w/cpp/language/explicit
		Converting constructors:	http://en.cppreference.com/w/cpp/language/converting_constructor
		Header files:				http://www.learncpp.com/cpp-tutorial/19-header-files/
		Const specifier:			https://stackoverflow.com/questions/13103755/intellisense-the-object-has-type-qualifiers-that-are-not-compatible-with-the-me
									https://stackoverflow.com/questions/751681/meaning-of-const-last-in-a-c-method-declaration
		Trailing nulls string:		https://softwareengineering.stackexchange.com/questions/181505/what-is-a-null-terminated-string
		Functional programming:		http://blog.madhukaraphatak.com/functional-programming-in-c++/
		Variadic functions:			http://en.cppreference.com/w/cpp/utility/variadic
		Variadic template:			https://stackoverflow.com/questions/25680461/variadic-template-pack-expansion
		Namespaces:					https://msdn.microsoft.com/en-us/library/5cb46ksf.aspx
		Lambda expression:			https://msdn.microsoft.com/en-us/library/dd293608.aspx
		Pointers:					http://www.cplusplus.com/doc/tutorial/pointers/
									https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html
		&& (Rvalue references):		https://stackoverflow.com/questions/5481539/what-does-t-double-ampersand-mean-in-c11
									https://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html
		Void pointers:				http://www.learncpp.com/cpp-tutorial/613-void-pointers/
	*/
}



// Function programming
void Notes::FunctionalTest() {
	auto printLn = [](const int number) {
		std::cout << number << std::endl;
	};
	std::vector<int> ints = { 2, 3, 4, 8, 9 };

	ShowText(ints, printLn);
}

void Notes::FunctionalTest(int* num1, int* num2, int* num3) {
	auto getNum = [&](int* num) {
		num1 = num2;
		std::cout << *num1 << " | " << *num2 << " | " << *num << std::endl;
	};

	getNum(num3);
}



// Template programming
template<typename Collection, typename Operation>
void Notes::ShowText(Collection col, Operation operation) {
	std::for_each(col.begin(), col.end(), operation);
}



TempNote::TempNote() : m_content() {}

TempNote::~TempNote() {}