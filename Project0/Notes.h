#pragma once

#include <iostream>
#include <string>



class TempNote;



class Notes {
public:
	// Non-local-static object
	static const int version = 0;
	static const float floatVersion; // can't initialize on class initializer, cock-blocked by standards
	// Local-static object
	TempNote& getTempNote();

	virtual void Show();

	// Function programming
	virtual void FunctionalTest();
	virtual void FunctionalTest(int* num1, int* num2, int* num3);
	
	// Inlining
	inline virtual void InlineTest();

	// Template/Generic programming
	template<typename Collection, typename Operation> void ShowText(Collection col, Operation operation);
};

// Inlining
inline void Notes::InlineTest() {
	std::cout << "Test" << std::endl;
}



class TempNote {
public:
	TempNote();
	~TempNote();

	std::string m_content;
};