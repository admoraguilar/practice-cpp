#include "Styles.h"
#include <iostream>
#include <algorithm>
#include <string>

Style::Style() {
	//std::cout << "Style constructor called." << std::endl;
}

Style::~Style() {
	//std::cout << "Style deconstructor called." << std::endl;
}

void Style::DoStyle() const {
	std::cout << "Style - DoStyle." << std::endl;
}



Header::Header(const std::string& title, const std::string& symbol, const int& symbolCount) :
	Style(), m_title(title), m_symbol(symbol), m_symbolCount(symbolCount) {
	//std::cout << "Header constructor called." << std::endl;
}

Header::~Header() {
	//std::cout << "Header deconstructor called." << std::endl;
}

void Header::DoStyle() const {
	//std::cout << "Header - DoStyle." << std::endl;
	std::string line = std::string();
	for(int i = 0; i < m_symbolCount; ++i) {
		line.append(m_symbol);
	}

	std::cout << line << std::endl;
	std::cout << " = " << m_title << std::endl;
	std::cout << line << std::endl;
}



Space::Space(const int& count) : 
	Style(), m_count(count) {
	//std::cout << "Space constructor called." << std::endl;
}

Space::~Space() {
	//std::cout << "Space deconstructor called." << std::endl;
}

void Space::DoStyle() const {
	//std::cout << "Space - DoStyle." << std::endl;
	for(int i = 0; i < m_count; ++i) std::cout << std::endl;
}