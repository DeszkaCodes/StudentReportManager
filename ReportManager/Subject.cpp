#include "Subject.h"
#include <sstream>

Subject::Subject(std::string name, std::vector<Grade> grades) {
	strcpy_s(this->name, name.c_str());

	this->grades = grades;
}

std::string Subject::getName() {
	return this->name;
}

float Subject::GetMean() {
	//Calculates sum of grades vector
	int sum = 0;
	unsigned short size = this->grades.size();

	for(unsigned short i = 0; i < size; i++)
	{
		sum += (int)grades[i];
	}

	return (float)sum / size;
}

std::string Subject::StringifyGrades() {
	std::string grades = "";

	for (unsigned short i = 0; i < this->grades.size(); i++)
	{
		grades += this->grades[i];

		if (i != this->grades.size())
			grades += '-';
	}

	return grades;
}

std::vector<Grade> Subject::StringToGrade(std::string rawGrades) {

	std::string rawGrade;

	std::vector<Grade> grades;

	std::stringstream s(rawGrades);

	while (std::getline(s, rawGrade, '-')) {
		
		Grade grade = (Grade)std::stoi(rawGrade);

		grades.push_back(grade);
	}

	return grades;
}