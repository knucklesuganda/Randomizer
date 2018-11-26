#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include "Student.h"
using namespace std;

class Randomizer {

	int diamonds;
	vector<Student> students;

public:
	Randomizer(int diamonds = 0, int students = 0);
	int getStudentsSize() const;

	bool setDiamonds(int diamonds);
	int getDiamonds() const;

	bool editStudentById(int id, string name, int diamonds, int grade);
	void setStudentGradeById(int id, int grade);
	void setStudentGradeTuple(int from, int to, int grade);
	void setAllgrade(int grade);

	void randomizeDiamonds();
	bool randomizeGrade(int id);
	void randomizeGradeTuple(int from = 0, int to = -1);

	void addnewStudent(string name, int diamonds, int grade);
	bool removeStudentById(int id);
	void removeStudentsTuple(int from, int to);
	void clearStudents(bool grades = false);

	string getStudentsInfo() const;
	string getStudentInfoById(int id) const;
};