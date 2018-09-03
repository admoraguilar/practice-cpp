#pragma once

#include <string>

#pragma region Item 1 - View C++ as a federation of languages

/*
	Paradigms you can do with C++:
		- Procedural
		- Object-oriented
		- Functional
		- Generic
		- Metaprogramming

	C++'s primary sub-languages:
		- C: Blocks, statements, preprocessor, built-in data types, arrays, pointers, etc.
			 No templates, no exceptions, no overloading.
		- Object-oriented C++: "C with classes", classes(constructors, destructors), encapsulation,
								inheritance, polymorphism, virtual functions (dynamic binding), etc.
		- Template C++: Generic programming. template<Class MyClass>
		- STL: A template library. Contains containers, iterators, algorithms, and function objects.
		   
	Key takeaways:
		- Pass-by-value is generally more efficient than pass-by-refernce for built-in-types.
		  Also the case for STL as iterators and function objects are modeled on pointers in C.
		- Pass-by-reference-to-const is usually better than pass-by-value for user defined types.
		  Also the case for template C++.
*/

#pragma endregion

#pragma region Item 2 - Prefer consts, enums, and inlines to "#defines"

/*
Key takeaways:
- For simple constants, prefer const objects or enums to #defines.
- For function-like macros, prefer inline functions to #defines.
*/

#define ITEM2_CONSTVARIABLE 0

const int Item2_ConstVariable = 0;

class Item2 {
public:
	// Enum hack to compensate for illegal static non-integral types
	enum {
		aValue = 0,
		aValue2 = 1,
	};

	inline int GetValue() const;
	template<typename T> inline int GetMaxValue(const T& a, const T& b);
};

inline int Item2::GetValue() const {
	return aValue;
}

template<typename T> inline int Item2::GetMaxValue(const T& a, const T& b) {
	return a > b ? a : b;
}

#pragma endregion

#pragma region Item 3 - Use consts whenever possible

#pragma endregion

#pragma region Item 4 - Make sure that objects are initialized before theyre used

#pragma endregion

#pragma region Item 5 - Know what functions C++ silently writes and calls

template<typename T>
class Item5 {
public:
	Item5(const std::string& name, const T& object);

	std::string& m_name;
	const T m_object;
};

template<typename T>
class Item5_Alt {
public:
	Item5_Alt(const std::string& name, const T& object);

	std::string* m_name;
	T* m_object;
};

#pragma endregion

#pragma region Item 21 - Prefer pass-by-reference-to-const to pass-by-value

/*
	Why are we doing this? 
		//
		void Execute(const Item21_ClassA& a);
		//
	instead of this
		//
		void Execute(Item21_ClassA a);
		//
	the reason for this is that the second expression is a pass-by-value type of parameter,
	the reason why it's bad is that once the method caller passes a value in it the method
	would construct "a" and call its copy constructor, once the method returns a value it
	also deconstructs "a". That's gonna be expensive if that class had alot of member variables
	or it inherited members from another class. The solution for this is by passing-by-ref which
	is the first expression, with that nothing is being created. The reason why we've added the 
	const specifier is to prevent modifications from the method as we're passing reference here
	not value.

	Doing this also prevents slicing problems:
		//
		Item21_ClassA_A a_a();
		Item21_Main m();

		m.Execute(a_a); // This will act like Item21_ClassA_A even though it requires Item21_ClassA
						// However if it's parameter is (Item21_ClassA a), then "a_a" will act like
						// Item21_ClassA and the overriden methods will not work.
		//
*/

class Item21_ClassA {
public:
	explicit Item21_ClassA();
	virtual void DoSomething() const;
};



class Item21_ClassA_A : public Item21_ClassA {
public:
	explicit Item21_ClassA_A();
	void DoSomething() const override;
};



class Item21_Main {
public:
	explicit Item21_Main();
	void Execute(const Item21_ClassA& a);
};

#pragma endregion