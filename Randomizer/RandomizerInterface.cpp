#include "RandomizerInterface.h"

RandomizerInterface::RandomizerInterface() {

	this->border += "#";
	for (size_t i = 0; i < 100; i++)
		this->border += "-";
	this->border += "#\n";

}

void RandomizerInterface::RandomizeDiamonds() {

	system("cls");
	this->random.randomizeDiamonds();
	this->showStudents();

	char choice;
	Text("You agree?").FastShow();
	cin >> choice;

	switch (choice) {

	case 'n':
		this->RandomizeDiamonds();
		break;

	default:
		break;
	}
}

void RandomizerInterface::setDiamonds() {

	int diamonds;
	Text("Write new diamonds number:", Cyan).showActive();
	cin >> diamonds;

	this->random.setDiamonds(diamonds);
}

void RandomizerInterface::setGrade() {

	system("cls");
	this->showStudents();

	int grade;
	Text("Write grade:", Magenta).showActive();
	cin >> grade;

	int choice;
	Text("1.By id\n", Green).showActive();
	Text("1.For tuple\n", Blue).showActive();
	Text("1.For all\n", Brown).showActive();

	cin >> choice;
	switch (choice) {

	case 1:
		int id;
		Text("Write id:", Green).showActive();
		cin >> id;
		this->random.setStudentGradeById(id, grade);
		break;

	case 2:
		int from, to;
		Text("Write first id:", Green).showActive();
		cin >> from;

		Text("Write last id:", Green).showActive();
		cin >> to;
		this->random.setStudentGradeTuple(from, to, grade);
		break;

	case 3:
		this->random.setAllgrade(grade);
		break;

	default:
		break;

	}

}

void RandomizerInterface::editStudents() {

	system("cls");

	string name;
	int grade, diamonds;
	this->showStudents();

	int id;
	Text("Write student id:").FastShow();
	cin >> id;

	Text("Write student name:").FastShow();
	cin.ignore();
	getline(cin, name);

	Text("Write student grade:").FastShow();
	cin >> grade;

	Text("Write student diamonds:").FastShow();
	cin >> diamonds;

	Student newStud(name, diamonds, grade);
	Text(newStud.getStudentInfo(), LightBlue).showActive();

	char choice;
	Text("You agree?").FastShow();
	cin >> choice;

	switch (choice) {

	case 'y':
		this->random.editStudentById(id, name, diamonds, grade);
		break;

	case 'n':
		this->editStudents();
		break;

	default:
		break;
	}

}

void RandomizerInterface::addStudents() {

	system("cls");
	string name;
	int grade, diamonds;

	Text("Write student name:").FastShow();
	cin.ignore();
	getline(cin, name);

	Text("Write student grade:").FastShow();
	cin >> grade;

	Text("Write student diamonds:").FastShow();
	cin >> diamonds;

	Student newStud(name, diamonds, grade);
	Text(newStud.getStudentInfo(), LightBlue).showActive();

	char choice;
	Text("You agree?").FastShow();
	cin >> choice;

	switch (choice) {

	case 'y':
		this->random.addnewStudent(name, diamonds, grade);
		break;

	case 'n':
		this->addStudents();
		break;

	default:
		break;
	}

}

void RandomizerInterface::showStudents()const {

	system("cls");
	Text("\tStudents:\n", Yellow).showActive();
	Text(this->random.getStudentsInfo()).FastShow();

	system("pause");
}

void RandomizerInterface::removeStudent() {

	system("cls");
	this->showStudents();

	int choice;
	Text("\t1.Delete by id\n", Cyan).showActive();
	Text("\t2.Delete fromto\n", Magenta).showActive();
	cin >> choice;

	switch (choice) {

	case 1:
		int id;
		Text("\tWrite student id:", Red).showActive();
		cin >> id;
		this->random.removeStudentById(id);
		break;

	case 2:
		int from, to;
		Text("\tWrite first border:", Red).showActive();
		cin >> from;

		Text("\tWrite last border:", Red).showActive();
		cin >> to;

		this->random.removeStudentsTuple(from, to);
		break;

	default:
		break;

	}

	system("cls");
	this->showStudents();
}

void RandomizerInterface::Builder(vector<Text> &fields, int lastField,
	vector<Text> predecorator, vector<Text> postdecorator) {

	system("cls");
	this->border.FastShow();

	for (Text &predecor : predecorator)
		predecor.FastShow();

	this->ShowOrientationMenu(fields, lastField);

	for (Text &postdecor : postdecorator)
		postdecor.FastShow();

	this->border.FastShow();
}

void RandomizerInterface::StudentsFunctions() {

	vector<Text> studtxt = {
		Text("Show Students(1)"),
		Text("Add Students(2)"),
		Text("Edit Students(3)"),
		Text("Remove Students(4)")
	};

	vector<Text> predecor(2);
	predecor[0] = Text("Students:" + to_string(this->random.getStudentsSize()) + "\t");

	orientationIn(studtxt, 2, predecor, vector<Text>());
}

void RandomizerInterface::RandomFunctions() {

	vector<Text> rndtxt = {
		Text("\tRandomize Diamonds(1)"),
		Text("Randomize Grade(2)")
	};

	this->orientationIn(rndtxt, 1, vector<Text>(), vector<Text>());
}

void RandomizerInterface::ShowOrientationMenu(vector<Text> &fields, int lastField) {

	for (size_t i = 0; i < lastField; i++) {
		fields[i].FastShow();
		cout << "\t";
	}

	fields[lastField].showActive();
	Text("\t").FastShow();

	for (size_t i = lastField + 1; i < fields.size(); i++) {
		fields[i].FastShow();
		cout << "\t";
	}

	cout << endl;
}

void RandomizerInterface::orientationIn(vector<Text>& fields, int index,
	vector<Text> predecorator, vector<Text> postdecorator) {

	int lastField = 0;

	while (true) {
		Builder(fields, lastField, predecorator, postdecorator);

		switch (orient()) {

		case GO_LEFT:
			if (lastField != 0)
				lastField--;
			break;

		case GO_RIGHT:
			if (lastField != fields.size() - 1)
				lastField++;
			break;

		case CHOOSE:
			this->chooser(lastField, index);
			break;

		case GO_BACK:
			return;

		default:
			break;

		}

	}

}

void RandomizerInterface::chooser(int lastField, int functionsSet) {

	switch (functionsSet) {

	case 0://main
		switch (lastField) {

		case 0:
			this->StudentsFunctions();
			break;

		case 1:
			this->RandomFunctions();
			break;

		case 2:
			this->Settings();

		default:
			break;

		}
		break;

	case 1://random functions
		switch (lastField) {

		case 0:
			this->RandomizeDiamonds();
			break;

		case 1:
			this->RandomizeGrade();
			break;

		default:
			break;

		}
		break;

	case 2://student functions
		switch (lastField) {

		case 0://students show
			this->showStudents();
			break;

		case 1://students add
			this->addStudents();
			break;

		case 3://students remove
			this->removeStudent();
			break;

		}
		break;

	case 3://settings
		switch (lastField) {

		case 0:
			this->setDiamonds();
			break;

		case 1:
			this->setGrade();
			break;

		default:
			break;

		}
		break;

	default:
		break;

	}

}

void RandomizerInterface::RandomizeGrade() {

	system("cls");
	this->showStudents();

	int choice;
	Text("\t1.Randomize by id\n", Cyan).showActive();
	Text("\t2.Randomize all\n", Magenta).showActive();
	Text("\t3.Randomize fromto\n", Brown).showActive();
	cin >> choice;

	switch (choice) {

	case 1:
		int id;
		Text("Write student id:", Blue).showActive();
		cin >> id;
		this->random.randomizeGrade(id);
		break;

		case 2:
			int from, to;
			Text("Write first border:", Red).showActive();
			cin >> from;

			Text("Write last border:", Red).showActive();
			cin >> to;

			this->random.randomizeGradeTuple(from, to);
			break;

		case 3:
			this->random.randomizeGradeTuple(from, to);
			break;

		default:
			break;

	}

	system("cls");

}

void RandomizerInterface::Settings() {

	system("cls");
	vector<Text> settFields = {

		Text("Set diamonds(1)"),
		Text("Set grade(2)"),

	};

	this->orientationIn(settFields, 3, vector<Text>(), vector<Text>());

}

void RandomizerInterface::start() {

	int diamonds;
	Text("Write number of diamonds:", Cyan).showActive();
	cin >> diamonds;
	this->random.setDiamonds(diamonds);

	int grade;
	Text("Write students standsrt grade:", Yellow).showActive();
	cin >> grade;
	this->random.setAllgrade(grade);

	vector<Text> maintxt = {
		Text("Students(1)"),
		Text("Randomize(2)"),
		Text("Settings(3)")
	};

	vector<Text> predecor(2);
	predecor[0] = Text("\tDiamonds:" + to_string(this->random.getDiamonds()), LightGray, Black, Cyan);
	predecor[1] = Text("\tStudents:" + to_string(this->random.getStudentsSize()) + "\t", LightGray, Black, Yellow);

	thread th(*MainMusic);
	th.detach();

	orientationIn(maintxt, 0, predecor, vector<Text>());
}