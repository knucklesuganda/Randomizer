#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include "Student.h"
using namespace std;

class Randomizer{

	int diamonds;
	vector<Student> students;

public:
	Randomizer(int diamonds = 0, int students = 0);
	int getStudentsSize() const;

	bool setDiamonds(int diamonds);
	int getDiamonds() const;

	bool editStudentById(int id, string name, int diamonds, int grade);
	void setAllgrade(int grade);

	void randomizeDiamonds();
	bool randomizeGrade(int id);

	void addnewStudent(string name, int diamonds, int grade);
	bool removeStudentById(int id);
	void clearStudents(bool grades = false);

	string getStudentsInfo() const;
	string getStudentInfoById(int id) const;
};