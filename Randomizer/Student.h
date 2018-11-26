#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {

	string name;
	int diamonds, grade;

public:
	Student(string name = "", int diamonds = 0, int grade = 0);

	void setStudentDiamonds(int diamonds);
	void setStudentName(string name);
	void setStudentGrade(int grade);

	int getStudentDiamonds() const;
	int getStudentGrade() const;
	string getStudentName() const;

	void increaseDiamonds();
	string getStudentInfo() const;
};