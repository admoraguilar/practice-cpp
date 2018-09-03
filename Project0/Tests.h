#pragma once

class Tests {
public:
	Tests();
	~Tests();
};



class A {
public:
	virtual void Do();
};



class B : public A {
public:
	void Do() override;
};



class TestUtilities {
public:
	void ReadA(A a);
};
