#include "VisionFunctions.h"

Text::Text(string txt, ConsoleColor text, ConsoleColor background, 
	ConsoleColor unactiveText, ConsoleColor unactiveBg){

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	txtPos.X = csbi.dwCursorPosition.X;
	txtPos.Y = csbi.dwCursorPosition.Y;

	this->SetText(txt);
	this->activeText = text;
	this->activeBg = background;

	this->unactiveText = unactiveText;
	this->unactiveBg = unactiveBg;

}

void Text::SetText(string txt){

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	txtPos.X = csbi.dwCursorPosition.X;
	txtPos.Y = csbi.dwCursorPosition.Y;
	this->txt = txt;

}

void Text::FastShow() const{
	cout << txt;
}

void Text::showActive()const {

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hStdOut, (WORD)((ConsoleColor(this->activeBg << 4)) | ConsoleColor(this->activeText)));
	this->FastShow();
	SetConsoleTextAttribute(hStdOut, (WORD)((ConsoleColor(this->unactiveBg << 4)) | ConsoleColor(this->unactiveText)));

}

string Text::getText() const{
	return this->txt;
}

Text & Text::operator+=(Text  str){
	
	this->txt += str.getText();
	return *this;

}

Text & Text::operator+=(string  str){
	this->txt += str;
	return *this;
}

//settings
Settings::Settings(){

	ifstream settings("Settings.txt");
	settings >> this->graphicdepth >> this->activeText >> this->activeBg 
		>> this->unactiveText >> this->unactiveBg;

}

int Settings::getGraphicDepth() const{
	return this->graphicdepth;
}

int Settings::getActiveText() const{
	return this->activeText;
}

int Settings::getUnActiveText() const{
	return this->unactiveText;
}

int Settings::getUnActiveBg() const{
	return this->unactiveBg;
}

int Settings::getActiveBg() const{
	return this->activeBg;
}

void MainMusic(){
	while (true) {

		PlaySound("MainMusic3.wav", NULL, SND_LOOP);
		PlaySound("MainMusic4.wav", NULL, SND_LOOP);
		PlaySound("MainMusic.wav", NULL, SND_LOOP);
		PlaySound("MainMusic2.wav", NULL, SND_LOOP);

	}
}