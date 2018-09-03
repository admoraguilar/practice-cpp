#include "Tests.h"
#include <iostream>

Tests::Tests() {}

Tests::~Tests() {}



void A::Do() {
	std::cout << "A" << std::endl;
}



void B::Do() {
	std::cout << "B" << std::endl;
}



void TestUtilities::ReadA(A a) {
	a.Do();
}