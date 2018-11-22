#pragma once
#include <iostream>
#include <Windows.h>
#include "Randomizer.h"
#include "GradeRandomizer.h"
#pragma comment(lib, "winmm.lib")
using namespace std;

class RandomizerInterface{

	string MAINMENU;
	Randomizer random;

	void RandomizeDiamonds();

	void loading() const;
	void greeting(string greeting, bool clear = true, int time = 50) const;

	void editStudents();
	void addStudents();
	void MainMenuBuilder();

	void ShowStudents() const;
	void RandomizeGrade();

	void Settings();

public:

	void start();
	void mainMenu();


};