#include "IOSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>

/*
* IO System error codes:
* 1: File not found
* 2: ID not found
*/


//IDRes class


IDRes::IDRes(bool isFound, unsigned short id, unsigned int row, std::string fileName) :
	found(isFound), row(row), fileName(fileName), id(id) {};

bool IDRes::getFound() {
	return this->found;
}

unsigned int IDRes::getRow() {
	return this->row;
}

std::string IDRes::getFileName() {
	return this->fileName;
}

unsigned short IDRes::getID() {
	return this->id;
}



IDRes IDRes::CheckID(unsigned short id, std::string csvName) {
	std::ifstream stream("Files/" + csvName + ".csv", std::ios::in);

	if (stream.is_open()) {

		//Temporary variable to hold the ID which was read.
		unsigned short readId;

		std::string line, column;

		unsigned int row = 0;

		while (getline(stream, line)) {
			row++;

			//To Skip the first row
			if (line[0] == '*')
				continue;

			std::stringstream s(line);

			getline(s, column, ',');

			readId = std::stoi(column);

			if (readId == id) {
				stream.close();

				return IDRes(true, id, row, csvName);
			}
		}
		stream.close();
	}

	return IDRes(false);
}

//IDRes end



//StudentIO namespace


void StudentIO::WriteData(Student student) {
	std::ofstream stream("Files/students.csv", std::ios::app | std::ios::out);

	if (stream.is_open()) {

		if (!IDRes::CheckID(student.getId(), "students").getFound()) {
			stream << student.getId() << ','
				<< student.getName() << ','
				<< student.height << ','
				<< student.weight << ','
				<< student.getBirthString() << ','
				<< student.getGenderChar() << '\n';
		}

		stream.close();
		
		std::vector<Subject> subjects;

		GradeIO::WriteData(student.getId(), subjects);
	}
}

Student StudentIO::ReadStudent(unsigned short id) {
	std::ifstream stream("Files/students.csv", std::ios::in);

	if (stream.is_open()) {

		std::vector<std::string> row;

		std::string line, column;

		while (getline(stream, line)) {
			if (line[0] == '*')
				continue;

			row.clear();

			std::stringstream s(line);

			while (getline(s, column, ',')) {
				row.push_back(column);
			}

			if (std::stoi(row[0]) == id) {
				
				std::vector<Subject> subjVec = GradeIO::ReadGrades(id);

				Student student(row[0], row[5][0], row[1], row[4], row[2], row[3], subjVec);

				return student;
			}
			else
				continue;
		}

		//If code reaches this far, it didn't found a student with the given ID
		throw 1;
	}
	else
		throw 2;
}

std::vector<Student> StudentIO::ReadAll() {
	std::ifstream stream("Files/students.csv", std::ios::in);

	if (stream.is_open()) {

		std::vector<Student> students;

		std::vector<std::string> row;

		std::string line, column;

		while (getline(stream, line)) {
			if (line[0] == '*')
				continue;

			row.clear();

			std::stringstream s(line);

			while (getline(s, column, ',')) {
				row.push_back(column);
			}

			std::cout << row[0];

			std::vector<Subject> subjVec = GradeIO::ReadGrades(std::stoi(row[0]));

			Student student(row[0], row[5][0], row[1], row[4], row[2], row[3], subjVec);

			students.push_back(student);
		}

		return students;

	}
	else
		throw 1;
}

//StudentIO end


//GradeIO namespace

void GradeIO::WriteData(unsigned short id, std::vector<Subject> subjects) {
	std::ofstream stream("Files/grades.csv", std::ios::app | std::ios::out);

	if (stream.is_open()) {

		if (subjects.size() > 0) {
			if (!IDRes::CheckID(id, "grades").getFound()) {
				stream << id << ','
					<< subjects[0].GradesToString() << ','
					<< subjects[1].GradesToString() << ','
					<< subjects[2].GradesToString() << ','
					<< subjects[3].GradesToString() << ','
					<< subjects[4].GradesToString() << ','
					<< subjects[5].GradesToString() << ','
					<< subjects[6].GradesToString() << '\n';
			}
		}
		else {
			if (!IDRes::CheckID(id, "grades").getFound()) {
				stream << id << ','
					<< ','
					<< ','
					<< ','
					<< ','
					<< ','
					<< ','
					<< '\n';
			}
		}

		stream.close();
	}
	else
		throw 1;
}

std::vector<Subject> GradeIO::ReadGrades(unsigned short id) {
	std::ifstream stream("Files/grades.csv", std::ios::in);

	if (stream.is_open()) {

		std::vector<Subject> subjects;

		std::vector<std::string> row;

		std::string line, column;

		bool found = false;

		while (getline(stream, line)) {
			if (line[0] == '*')
				continue;

			row.clear();

			std::stringstream s(line);

			while (getline(s, column, ',')) {
				row.push_back(column);

				if (std::stoi(row[0]) == id)
					found = true;
				else
					break;

			}

			if (found) {
				for (short i = 1; i < row.size(); i++)
				{
					std::string subjName = IntToName(i);

					Subject subj(subjName, row[i]);

					subjects.push_back(subj);
				}

				return subjects;
			}
			else
				continue;
		}

		//If code reaches this far, it didn't found a student with the given ID
		throw 2;
	}
	else
		throw 1;
}

//NEEDS TO BE CHANGED INTO SOMETHING AUTOMATIC
std::string GradeIO::IntToName(short index)
{
	switch (index) {
	case 1:
		return "Math";
		break;
	case 2:
		return "P.E.";
		break;
	case 3:
		return "Art";
		break;
	case 4:
		return "History";
		break;
	case 5:
		return "Grammar";
	case 6:
		return "R.E.";
		break;
	case 7:
		return "I.T.";
		break;
	default:
		return "Error";
	}
}

//GradeIO end