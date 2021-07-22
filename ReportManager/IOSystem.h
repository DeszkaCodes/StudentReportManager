#pragma once
#include "Person.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

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
}

namespace GradeIO {

}
