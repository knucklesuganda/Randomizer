#include "Student.h"

Student::Student(string name, int diamonds, int grade) {

	this->setStudentDiamonds(diamonds);
	this->setStudentName(name);
	this->setStudentGrade(grade);

}

void Student::setStudentDiamonds(int diamonds) {

	if (diamonds >= 0 && diamonds <= 6)
		this->diamonds = diamonds;
	else
		this->diamonds = 0;

}

void Student::setStudentName(string name) {
	this->name = name;
}

void Student::setStudentGrade(int grade) {

	if (grade >= 0 && grade <= 12)
		this->grade = grade;
	else
		this->grade = 0;

}

int Student::getStudentDiamonds() const {
	return this->diamonds;
}

int Student::getStudentGrade() const {
	return this->grade;
}

void Student::increaseDiamonds() {
	this->diamonds++;
}

string Student::getStudentName() const {
	return this->name;
}

string Student::getStudentInfo() const {
	return "Name:" + this->name + "\tGrade:" + to_string(this->grade)
		+ "\tDiamonds:" + to_string(this->diamonds) + "\n";
}