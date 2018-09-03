#include "Puzzles.h"
#include <iostream>
#include <string>



Puzzle::Puzzle() {

}

void Puzzle::Execute() {

}



// Reference: http://www.geeksforgeeks.org/swap-two-numbers-without-using-temporary-variable/
SwapVariables::SwapVariables(int a, int b) : Puzzle() {
	this->a = a;
	this->b = b;
}

void SwapVariables::Execute() {
	if (a > b) {
		a = a - b; // a becomes 15
		b = b + a; // b becomes 45
		a = b - a; // a becomes 30
	}
	else {
		a = b - a;
		b = b - a;
		a = b + a;
	}

	/*a = a * b;
	b = a / b;
	a = a / b;*/

	std::cout << "A: " << a << "| B: " << b << std::endl;
}



// Reference: http://www.programmerinterview.com/index.php/puzzles/2-eggs-100-floors-puzzle/
EggsAndFloors::EggsAndFloors(int floors, int eggs, int threshold) : Puzzle() {
	this->floors = floors;
	this->eggs = eggs;
	this->threshold = threshold;
}

void EggsAndFloors::Execute() {

#pragma region Binary search
	/*int currentFloor = 0;
	int lastFloor = 0;
	int min = 0;
	int max = 0;
	int dropCount = 0;
	int eggsUsed = 0;

	min = 0;
	max = floors;

	while (eggsUsed < eggs) {
		bool eggBroken = false;

		currentFloor = min + (max - min) * .5f;
		eggBroken = currentFloor > threshold;

		std::cout << "#" + std::to_string(eggsUsed) + " is dropped at " + std::to_string(currentFloor) + "[Min: " + std::to_string(min) + " , Max: " + std::to_string(max) + "]" << std::endl;

		if (eggBroken) {
			max = currentFloor;
			std::cout << "#" + std::to_string(eggsUsed) + " was broken." << std::endl;
			eggsUsed++;
		} else {
			min = currentFloor;
		}

		if (currentFloor == lastFloor) {
			eggsUsed = eggs + 1;
			std::cout << "Program end." << std::endl;
		}

		lastFloor = currentFloor;
	}

	if (currentFloor == threshold) std::cout << "Floor threshold is at: " + std::to_string(threshold) << std::endl;
	else std::cout << "All eggs broken, failed to determine floor threshold" << std::endl;*/
#pragma endregion

#pragma region Modified Linear Search
	int currentFloor = 0;
	int iterationDifference = 10;
	int iterationCount = 0;
	int eggsUsed = 0;
	int searchMode = 0;
	int min = 0;
	int max = 0;

	while (eggsUsed < eggs) {
		bool isEggBroke = currentFloor > threshold;

		if (isEggBroke) {
			eggsUsed++;
		}

		switch (searchMode) {
		case 0:
			if (isEggBroke) {
				searchMode = 1;
				max = currentFloor;
				currentFloor = min;
				break;
			} else {
				min = currentFloor;
			}

			currentFloor += iterationDifference;

			break;
		case 1:
			if (isEggBroke) {
				currentFloor--;
				break;
			}

			currentFloor++;
			break;
		}

		iterationCount++;
	}

	std::cout << "[Iteration count: " << iterationCount << "] Threshold is at " << currentFloor << std::endl;
#pragma endregion

}
