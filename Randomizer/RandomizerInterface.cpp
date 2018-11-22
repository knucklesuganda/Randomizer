#include "RandomizerInterface.h"

void RandomizerInterface::loading() const {

	system("cls");

	for (size_t i = 0; i < 20; i++){

		for (size_t j = 0; j < 100; j++)
			cout << '#';

		Sleep(50);
	}

	system("cls");

}

void RandomizerInterface::greeting(string greeting, bool clear, int time) const{

	for (size_t i = 0; i < greeting.length(); i++) {
		cout << greeting[i];
		Sleep(time);
	}
	
	Sleep(1000);

	if(clear)
		system("cls");

}

void RandomizerInterface::editStudents(){

	int id;
	greeting("Write id of student", false);
	cin >> id;

	string info = this->random.getStudentInfoById(id);

	if (info == "NoneStud") {

		greeting("Wrong student id!");
		return;

	}

	char correct;
	greeting(info + "\nCorrect student?", false, 50);
	cin >> correct;

	if (correct != 'y' && correct != 'Y') {

		greeting("Send you to start...");
		this->editStudents();

	}

	string name;
	greeting("Write student name:", false);
	cin >> name;

	int diamonds;
	greeting("Write student diamonds:", false);
	cin >> diamonds;

	int grade;
	greeting("Write student grade:", false);
	cin >> grade;

	greeting("Creating student...");
	Student tmp(name, diamonds, grade);

	char choice;
	greeting("Your student will be\n" + tmp.getStudentInfo() + "y/n", false);
	cin >> choice;

	if (choice == 'y' && choice == 'Y')
		this->random.editStudentById(id, name, diamonds, grade);
	else {

		greeting("Trying again...");
		this->editStudents();

	}

}

void RandomizerInterface::addStudents(){

	string name;
	greeting("Write student name:", false);
	cin >> name;

	int diamonds;
	greeting("Write student diamonds:", false);
	cin >> diamonds;

	int grade;
	greeting("Write student grade:", false);
	cin >> grade;

	greeting("Creating student...");
	Student tmp(name, diamonds, grade);

	char choice;
	greeting("Your student will be\n" + tmp.getStudentInfo() + "y/n", false);
	cin >> choice;

	if (choice == 'y' || choice == 'Y')
		this->random.addnewStudent(name, diamonds, grade);
	else {

		greeting("Trying again...");
		this->addStudents();

	}

}

void RandomizerInterface::RandomizeDiamonds(){

	greeting("Randomize diamonds...");
	this->random.randomizeDiamonds();
	this->ShowStudents();

	char choice;
	greeting("You agree?", false);
	cin >> choice;

	if (choice != 'y' || choice != 'Y') {

		this->random.clearStudents();
		this->RandomizeDiamonds();

	}

}

void RandomizerInterface::ShowStudents() const{
	greeting("\tStudents info" + this->random.getStudentsInfo(), false);
}

void RandomizerInterface::RandomizeGrade(){

	int id;
	greeting("Write student id:", false);
	cin >> id;

	this->random.randomizeGrade(id);

}

void RandomizerInterface::Settings(){

	this->MAINMENU = "\t#----------------------------------------------------------------#\n";
	this->MAINMENU += "\t#\tDiamonds(1):" + to_string(this->random.getDiamonds()) + "\tColors(2):" + to_string(this->random.getStudentsSize()) + "\t#\n";
	this->MAINMENU += "\t#----------------------------------------------------------------#\n";

	greeting(this->MAINMENU, false, 20);

	int choice;
	cin >> choice;

	switch(choice){

		case 1:
			int diamonds;
			greeting("Write diamonds:", false);
			cin >> diamonds;

			this->random.setDiamonds(diamonds);
			greeting("Diamonds succesfully setted to:" + to_string(diamonds));
			return;

		case 2:
			char color[2];
			greeting("Write 'color' + keys:", false);

			cin.clear();
			cin.getline(color, 2);
			system(color);
			return;

	}

}

void RandomizerInterface::MainMenuBuilder(){

	this->MAINMENU = "\t#----------------------------------------------------------------#\n";
	this->MAINMENU += "\t#\tDiamonds:" + to_string(this->random.getDiamonds()) 
		+ "\tStudents:" + to_string(this->random.getStudentsSize()) + "                               #\n";

	this->MAINMENU += "\t#\tEdit students(1)\tAdd student(2)                   #\n";
	this->MAINMENU += "\t#\tRandomizeDiamonds(3)\tRandomize grade(4)               #\n";

	this->MAINMENU += "\t#\tShow students(5)\tSettings(4)                      #\n";
	this->MAINMENU += "\t#----------------------------------------------------------------#\n";

}

void RandomizerInterface::start() {

	greeting("Hello");
	greeting("You are in randomizer 228-1337");
	greeting("If you arent Asslan and want to play type 'y'\n", false);

	char choice;
	cin >> choice;

	if (choice != 'y' && choice != 'Y') {

		greeting("Goodbye");
		this->~RandomizerInterface();
		return;

	}

	greeting("Good boy...");
	//auto mainMusic = thread(PlaySound(TEXT("MainMusic.wav"), NULL, SND_LOOP), this);

	int diamonds;
	greeting("Write diamonds number:", false);
	cin >> diamonds;

	greeting("Recieving diamonds...");
	greeting("Diamonds succesfully recieved!");
	this->random.setDiamonds(diamonds);

	greeting("Getting list of students");

	if (this->random.getStudentsSize() > 0) {

		greeting("\tStudents\n" + this->random.getStudentsInfo(), false, 20);

		char goodStudents;
		greeting("Is it ok? y/n", false);
		cin >> goodStudents;

		if (goodStudents != 'y' && goodStudents != 'Y')
			this->editStudents();

	}else {

			greeting("You dont have any students");
			greeting("You need to append one");
			this->addStudents();

	}

	greeting("One second...");
	greeting("Lets start!");

	this->mainMenu();
}

void RandomizerInterface::mainMenu(){

	while (true) {

		this->MainMenuBuilder();
		greeting(MAINMENU, false, 5);

		int choice;
		cin >> choice;

		switch (choice){

			case 1:
				system("cls");
				this->editStudents();
				break;

			case 2:
				system("cls");
				this->addStudents();
				break;

			case 3:
				system("cls");
				this->RandomizeDiamonds();
				break;

			case 4:
				system("cls");
				this->RandomizeGrade();
				break;

			case 5:
				system("cls");
				this->ShowStudents();
				system("pause");
				break;

			case 6:
				this->Settings();

			default:
				greeting("Cant find command\n", false);
				break;
		}

		system("cls");

	}

}