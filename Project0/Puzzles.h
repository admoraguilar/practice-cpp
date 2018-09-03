#pragma once


class Puzzle {
public:
	explicit Puzzle();
	virtual void Execute();
};



// Reference: http://www.geeksforgeeks.org/swap-two-numbers-without-using-temporary-variable/
class SwapVariables : public Puzzle {
private:
	int a = 56;
	int b = 89;

public:
	explicit SwapVariables(int a, int b);
	void Execute() override;
};



// Reference: http://www.programmerinterview.com/index.php/puzzles/2-eggs-100-floors-puzzle/
class EggsAndFloors : public Puzzle {
private:
	int floors = 100;
	int eggs = 2;
	int threshold = 51;

public:
	explicit EggsAndFloors(int floors, int eggs, int threshold);
	void Execute() override;
};