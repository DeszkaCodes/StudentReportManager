#pragma once
#include "Person.h"


/*
* Class to help in editing and deleting records
* It saves the row of the ID in the files and even the file name.
*/
class IDRes {
public:
	bool getFound();
	unsigned int getRow();
	std::string getFileName();
	unsigned short getID();

	static IDRes CheckID(unsigned short id, std::string csvName);

private:
	IDRes(bool isFound, unsigned short id = 0, unsigned int row = 0, std::string fileName = "None");

	const bool found = false;
	const unsigned int row;
	const std::string fileName;
	unsigned short id;
};

namespace StudentIO {
	void WriteData(Student student);

	Student ReadStudent(unsigned short id);

	std::vector<Student> ReadAll();

	void EditData(unsigned short id, Student student);
}

namespace GradeIO {
	void WriteData(unsigned short id, std::vector<Subject> subjects);

	std::vector<Subject> ReadGrades(unsigned short id);

	void EditData(unsigned short id, std::vector<Subject> subjects);

	std::string IntToName(short index);
}
