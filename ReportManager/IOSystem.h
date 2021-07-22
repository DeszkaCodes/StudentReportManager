#pragma once
#include "Person.h"


/*
* Class to help in editing and deleting records
* It saves the row of the ID in the files and even the file name.
*/
class IDRes {
public:
	IDRes(bool isFound, unsigned int row = 0, std::string fileName = "None");

	bool getFound();
	unsigned int getRow();
	std::string getFileName();

	static IDRes CheckID(unsigned short id, std::string csvName);

private:
	const bool found = false;
	const unsigned int row;
	const std::string fileName;
};

namespace StudentIO {
	void WriteData(Student student);

	Student ReadStudent(unsigned short id);

	Student* ReadAll();

	void EditData(unsigned short id, Student student);
}

namespace GradeIO {
	void WriteData(unsigned short id, Subject subjects[]);

	Subject* ReadGrades(unsigned short id);

	Subject** ReadAll();

	void EditData(unsigned short id, Subject subjects[]);
}
