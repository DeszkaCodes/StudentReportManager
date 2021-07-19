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
	Subject(std::string name, std::vector<Grade> grades);
	std::string getName();
	std::vector<Grade> grades;


	//Calculator functions
	float GetMean();

private:
	char name[20];
};

#endif // !Subject_H


