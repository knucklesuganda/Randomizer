#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <thread>
#include <conio.h>
#include "stdarg.h"
#include "Randomizer.h"
#include "VisionFunctions.h"
#pragma comment(lib, "winmm.lib")
using namespace std;

class RandomizerInterface {

	enum Keys {
		GO_LEFT,
		GO_RIGHT,
		CHOOSE,
		GO_BACK
	};

	Text border;
	Randomizer random;

	void editStudents();
	void addStudents();
	void removeStudent();
	void showStudents() const;

	void Builder(vector<Text> &fields, int lastField, vector<Text> predecorator, vector<Text> postdecorator);
	void StudentsFunctions();
	void RandomFunctions();

	void RandomizeGrade();
	void RandomizeDiamonds();

	void setDiamonds();
	void setGrade();
	void Settings();

	Keys orient() const {

		while (true) {
			switch (_getch()) {

			case 'd':
			case (char)16:
				return GO_RIGHT;

			case 'a':
			case (char)17:
				return GO_LEFT;

			case (char)13:
				return CHOOSE;

			case (char)27:
				return GO_BACK;

			default:
				break;

			}
		}

	}
	void ShowOrientationMenu(vector<Text> &fields, int lastField);
	void orientationIn(vector<Text>& fields, int index, vector<Text> predecorator, vector<Text> postdecorator);
	void chooser(int lastField, int functionsSet);

public:
	RandomizerInterface();
	void start();

};