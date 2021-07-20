#include <vector>
#include <string>
#include <numeric>

#ifndef Subject_H
#define Subject_H

enum Grade {
	A = 5,
	B = 4,
	C = 3,
	D = 2,
	F = 1
};

class Subject {
public:
	//Setup and value change functions
	Subject(std::string name, std::vector<Grade> grades, unsigned short daysMissing = 0);
	std::string getName();
	std::vector<Grade> grades;
	unsigned short daysMissed;

	//Calculator functions
	float GetMean();
	std::string StringifyGrades();

private:
	char name[20];
};

#endif // !Subject_H


