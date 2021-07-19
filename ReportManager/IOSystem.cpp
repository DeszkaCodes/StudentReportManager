#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "IOSystem.h"

void StudentIO::WriteData(Student student) {
	while (StudentIO::CheckID(student.getId())) {
		student.RegenID();
	}

	std::ofstream stream("Files/students.csv", std::ios::app | std::ios::out);

	if (stream.is_open()) {
		stream << student.getId() << ','
			<< student.getName() << ','
			<< student.getHeight() << ','
			<< student.getWeight() << '\n';
	}

	stream.close();
}

/*Student* StudentIO::ReadAllData() {
	std::ifstream stream("Files/students.csv", std::ios::in);

	std::string line, word;

	std::vector<Student> row;

	while (std::getline(stream, line)) {

		std::stringstream s(line);

		short count = 0;
		while (std::getline(s, word, ',')) {

		}
	}
}*/

//Returns true if the given ID already exists
bool StudentIO::CheckID(unsigned short id) {
	std::ifstream stream("Files/students.csv", std::ios::in);

	std::string line, word;

	std::vector<unsigned short> row;

	while (std::getline(stream, line)) {

		if (line[0] == '*')
			continue;

		row.clear();

		std::stringstream s(line);

		std::getline(s, word, ',');

		int readId = std::stoi(word);

		if (readId == id) {
			stream.close();

			return true;
		}
	}

	return false;
}