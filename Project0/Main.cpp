#include <iostream>
#include <ctime>
#include <cstdarg>
#include <conio.h>
#include <string>
#include <typeinfo>
#include "Items.h"
#include "Notes.h";
#include "Puzzles.h"
#include "Tests.h"
#include "Styles.h"

/*
	This project is a culmination of the things I've learned throughout Scott Meyers's Effective C++ Book 3rd Edition.
	Albeit there are some extras such as solution to famous interview programming puzzles.
*/

void ShowItems();
void ShowNotes();
void ShowTempNotesInit();
void ShowTempNotes();
void ShowPuzzles();
void ShowTests();

std::string lol;

const SwapVariables sv(0, 0);

void main() {
	// Styles
	/*Header* itemsHeader = new Header("Items", "-", 30);
	Header* notesHeader = new Header("Notes", "-", 30);
	Header* puzzlesHeader = new Header("Puzzles", "-", 30);
	Header* testsHeader = new Header("Tests", "-", 30);
	Space* space = new Space(2);;

	itemsHeader->DoStyle();
	ShowItems();
	space->DoStyle();

	notesHeader->DoStyle();
	ShowNotes();
	ShowTempNotesInit();
	ShowTempNotes();
	space->DoStyle();*/

	/*puzzlesHeader->DoStyle();
	ShowPuzzles();
	space->DoStyle();

	testsHeader->DoStyle();
	ShowTests();
	space->DoStyle();*/

	//std::cout << typeid("test").name() << std::endl;
	
	//srand(time(NULL));
	//int arr[100];
	//for(int i = 0; i < 100; ++i) {
	//	arr[i] = i + 1;
	//}
	//arr[rand() % 100 + 1] = 0;

	//int sum = 0;
	//for(int i = 0; i < 100; ++i) {
	//	std::cout << arr[i] << std::endl;
	//	sum += arr[i];
	//}

	//int numberChangeIndex = 5050 - sum;
	//std::cout << "Test: " << std::endl;
	//std::cout << "The number that was changed was: " << numberChangeIndex << std::endl;

	int num = 0;
	int num2 = ((++num) + ++num);

	std::cout << num2;

	_getch();
}



void ShowItems() {
	Item2* item2 = new Item2();
	std::cout << item2->GetMaxValue(2, 4) << std::endl;
	delete item2;

	/*std::string item5AKey = "A";
	std::string item5BKey = "B";

	Item5<int> item5a(item5AKey, 0);
	Item5<int> item5b(item5BKey, 0);

	item5a = item5b;

	Item5_Alt<int> item5_alt_a(item5AKey, 0);
	Item5_Alt<int> item5_alt_b(item5BKey, 0);

	item5_alt_a = item5_alt_b;*/
}

int t = 999;
int* getTest() {
	return &t;
}

int& getTestRef() {
	return t;
}

void ShowNotes() {
	std::cout << "Get test ref:" << std::endl;
	std::cout << getTestRef() << std::endl;
	getTestRef() = 2;
	std::cout << getTestRef() << std::endl;
	std::cout << &getTestRef() << std::endl;

	std::cout << "Get test:" << std::endl;
	int* te = &t;
	std::cout << getTest() << std::endl;
	std::cout << &t << std::endl;
	std::cout << &te << std::endl;
	std::cout << *te << std::endl << std::endl;

	Notes* note = new Notes();
	note->FunctionalTest();
	note->InlineTest();

	int* num1 = new int(1);
	int* num2 = new int(2);
	int* num3 = new int(3);

	note->FunctionalTest(num1, num2, num3);

	delete num1;
	delete num2;
	delete num3;
}

void ShowTempNotesInit() {
	Notes* note = new Notes();
	TempNote& tempNote = note->getTempNote();
	tempNote.m_content = "Test";

	std::cout << "Note version: " << note->version << std::endl;
	std::cout << "Temp note: " << tempNote.m_content << std::endl;

	delete note;
}

void ShowTempNotes() {
	Notes* note = new Notes();
	TempNote tempNote = note->getTempNote();
	std::cout << "Note version: " << note->version << std::endl;
	std::cout << "Temp note 2: " << tempNote.m_content << std::endl;

	delete note;
}

void ShowPuzzles() {
	SwapVariables sv(1, 0);
	EggsAndFloors ef(100, 2, 69);

	Puzzle p = sv;

	sv.Execute();
	ef.Execute();
}

void ShowTests() {
	B* b1 = new B();
	TestUtilities* t = new TestUtilities();
	t->ReadA(*b1);

	delete b1;
	delete t;
}