#pragma once

#include <string>

class Style {
public:
	Style();
	virtual ~Style();

	virtual void DoStyle() const = 0;
};



class Header : public Style {
public:
	Header(const std::string& title, const std::string& symbol, const int& symbolCount);
	~Header() override;

	void DoStyle() const override;

private:
	std::string m_title;
	std::string m_symbol;
	int m_symbolCount;
};



class Space : public Style {
public:
	Space(const int& count);
	~Space() override;

	void DoStyle() const override;

private:
	int m_count;
};