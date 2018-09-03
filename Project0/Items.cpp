#include "Items.h"

#include <string>

#pragma region Item 5 - Know what functions C++ silently writes and calls

template<typename T>
Item5<T>::Item5(const std::string& name, const T& object) {

}

template<typename T>
Item5_Alt<T>::Item5_Alt(const std::string& name, const T& object) {
	m_name = name;
	m_object = object;
}

#pragma endregion

#pragma region Item 21 - Prefer pass-by-reference-to-const to pass-by-value

Item21_ClassA::Item21_ClassA() {}

void Item21_ClassA::DoSomething() const {}



Item21_ClassA_A::Item21_ClassA_A() {}

void Item21_ClassA_A::DoSomething() const {}



Item21_Main::Item21_Main() {}

void Item21_Main::Execute(const Item21_ClassA& a) {
	a.DoSomething();
}

#pragma endregion