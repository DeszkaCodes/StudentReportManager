#include <vector>
#include <string>
#include <numeric>

#ifndef Subject_H
#define Subject_H

enum class SubjectName: short {
	Math = 1,
	PE = 2,
	History = 3,
	Grammar = 4,
	Art = 5,
	RE = 6,
	IT = 7 
};

class Subject {
public:
	//Setup and value change functions
	Subject(SubjectName name, std::vector<short> grades);
	std::string getName();
	std::vector<short> grades;

	//Calculator functions
	float GetMean();
	std::string StringifyGrades();

	//Static functions
	static std::vector<short> StringToGrade(std::string rawGrades);

private:
	SubjectName name;
};

#endif // !Subject_H


