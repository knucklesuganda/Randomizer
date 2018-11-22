#include "Randomizer.h"

Randomizer::Randomizer(int diamonds, int students){

	srand(time(NULL));
	this->setDiamonds(diamonds);

	this->students.push_back(Student("andrey"));
	this->students.push_back(Student("aslan"));
	this->students.push_back(Student("dulat"));

}

int Randomizer::getStudentsSize() const{
	return this->students.size();
}

bool Randomizer::setDiamonds(int diamonds){

	if (diamonds > 0) {
		this->diamonds = diamonds;
		return true;
	}

	return false;
}

int Randomizer::getDiamonds() const{
	return this->diamonds;
}

bool Randomizer::editStudentById(int id, string name, int diamonds, int grade){

	if (id < 0 || id > this->students.size())
		return false;

	this->students[id].setStudentName(name);
	this->students[id].setStudentDiamonds(diamonds);
	this->students[id].setStudentGrade(grade);

}

void Randomizer::setAllgrade(int grade){

	for (size_t i = 0; i < grade; i++)
		this->students[i].setStudentGrade(grade);

}

void Randomizer::randomizeDiamonds(){

	for (size_t i = 0; i < this->diamonds; i++) {

		int luckyStudent = (rand() % static_cast<int>(this->students.size() + 1)) + 1;

		while (this->students[luckyStudent].getStudentDiamonds() >= 6)
			luckyStudent = rand() % this->diamonds + 1;

		this->students[luckyStudent].increaseDiamonds();
		this->diamonds--;

	}
}

bool Randomizer::randomizeGrade(int id){

	if (id < 0 || id > this->students.size())
		return false;

	GradeRandomizer gr;
	this->students[id].setStudentGrade(rand()%12 + 6);

}

void Randomizer::addnewStudent(string name, int diamonds, int grade){
	this->students.push_back(Student(name, diamonds, grade));
}

void Randomizer::clearStudents(bool grades){

	for (size_t i = 0; i < this->students.size(); i++)
		this->students[i].setStudentDiamonds(0);

	if (grades) {

		for (size_t i = 0; i < this->students.size(); i++)
			this->students[i].setStudentGrade(0);

	}

}

string Randomizer::getStudentsInfo() const{

	string info = this->students[0].getStudentInfo();

	for (int i = 1; i < this->students.size(); i++)
		info += this->students[i].getStudentInfo();

	return info;
}

string Randomizer::getStudentInfoById(int id) const{

	if (id < 0 || id > this->students.size())
		return "NoneStud";

	return this->students[id].getStudentInfo();
}