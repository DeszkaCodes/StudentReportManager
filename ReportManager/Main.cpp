/*
	CODE CREATED BY NORBERT ORMÁNDI

	ALL RIGHTS RESERVED©
*/
#include "Person.h"
#include "Subject.h"
#include "IOSystem.h"
#include <iostream>
#include <chrono>
#include <thread>

namespace StudentUI {

	void Show();
	void ShowAll();

	//void Create();
}

namespace GradeUI {

}

int main() {
	short choice;

	std::cout << "Press 1 to view students\n"
		<< "Press 2 to view all students\n"
		<< "Press 3 to create a new student\n";

	do {
		try {
			std::cin >> choice;
			break;
		}
		catch(...){
			std::cout << "Given input was in an incorrect format.";
		}
	} while (true);

	switch (choice) {
	case 1:
		StudentUI::Show();
		break;
	case 2:
		StudentUI::ShowAll();
		break;
	case 3:
		//StudentUI::Create();
		break;
	default:
		std::cout << "Exiting...";
		std::this_thread::sleep_for(std::chrono::seconds(5));
		return 0;
	}
}

void StudentUI::Show() {
	unsigned short choice;

	std::cout << "Type in the student ID (0-65535)\n";

	do {
		try {
			std::cin >> choice;
			break;
		}
		catch (...) {
			std::cout << "Given input was in an incorrect format.";
		}
	} while (true);

	IDRes result = IDRes::CheckID(choice, "students");

	if (result.getFound()) {
		Student student = StudentIO::ReadStudent(result.getID());

		std::cout << "Name: " + student.getName() + '\n'
			<< "Gender: " + student.getGenderStr() + '\n'
			<< "Birthdate: " + student.getBirthString() + '\n'
			<< "Height: " + std::to_string(student.height) + " Weight: " + std::to_string(student.weight) + '\n';

		std::vector<Subject> subjects = student.getSubjects();

		for (int i = 0; i < subjects.size(); i++) {
			std::cout << "Subject: " + subjects[i].getName() + '\n'
				<< "Grades: " + subjects[i].GradesToString() + '\n'
				<< "Average: " + std::to_string(subjects[i].GetMean()) + '\n' + '\n'; 
		}

		main();
	}
	else {
		std::cout << "No student was found with this ID.\n\n";

		main();
	}
}

void StudentUI::ShowAll()
{
	std::vector<Student> students = StudentIO::ReadAll();

	for (auto &student : students)
	{
		std::cout << "ID: " + student.getId() + '\n'
			<< "Name: " + student.getName() + '\n'
			<< "Gender: " + student.getGenderStr() + '\n'
			<< "Birthdate: " + student.getBirthString() + '\n'
			<< "Height: " + std::to_string(student.height) + " Weight: " + std::to_string(student.weight) + '\n';

		std::vector<Subject> subjects = student.getSubjects();

		for (int i = 0; i < subjects.size(); i++) {
			std::cout << "Subject: " + subjects[i].getName() + '\n'
				<< "Grades: " + subjects[i].GradesToString() + '\n'
				<< "Average: " + std::to_string(subjects[i].GetMean()) + '\n' + '\n';
		}

		std::cout << "\n\n\n";
	}
}
