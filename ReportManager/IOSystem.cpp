#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "IOSystem.h"

bool CheckID(unsigned short id, std::string file) {
	const std::string file = "Files/" + file;

	std::ifstream stream(file, std::ios::in);

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

//StudentIO
void StudentIO::WriteData(Student student) {
	while (CheckID(student.getId(), "students.csv")) {
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

//GradeIO
void GradeIO::WriteData(Student student) {
	std::ofstream stream("Files/grades.csv", std::ios::out, std::ios::app);

	if (stream.is_open()) {
		if (!CheckID(student.getId(), "grades.csv")) {
			stream << student.getId() << ','
				<< student.getSubject(0).StringifyGrades() << ','
				<< student.getSubject(1).StringifyGrades() << ','
				<< student.getSubject(2).StringifyGrades() << ','
				<< student.getSubject(3).StringifyGrades() << ','
				<< student.getSubject(4).StringifyGrades() << ','
				<< student.getSubject(5).StringifyGrades() << ','
				<< student.getSubject(6).StringifyGrades() << '\n';
		}
	}
}

