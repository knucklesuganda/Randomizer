#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

enum ConsoleColor {
	Black, Blue, Green, Cyan, Red, Magenta, Brown,
	LightGray, DarkGray, LightBlue, LightGreen,
	LightCyan, LightRed, LightMagenta, Yellow, White
};

class Settings {

	int unactiveText;
	int activeText;

	int unactiveBg;
	int activeBg;

public:
	Settings();

	int getActiveText() const;
	int getUnActiveText() const;

	int getUnActiveBg() const;
	int getActiveBg() const;

};

void MainMusic();

class Text {

	int activeText;
	int activeBg;
	int unactiveText;
	int unactiveBg;

	string txt;
	COORD txtPos;
	Settings stg;

public:
	Text(string txt = "", ConsoleColor text = ConsoleColor(Settings().getActiveText()),
		ConsoleColor background = ConsoleColor(Settings().getActiveBg()),
		ConsoleColor unactiveText = ConsoleColor(Settings().getUnActiveText()),
		ConsoleColor unactiveBg = ConsoleColor(Settings().getUnActiveBg()));

	void SetText(string txt);

	void FastShow() const;
	void showActive() const;

	string getText() const;

	Text &operator+=(Text str);
	Text &operator+=(string str);

};