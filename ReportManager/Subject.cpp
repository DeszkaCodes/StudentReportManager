#include "Subject.h"

Subject::Subject(std::string name, std::vector<Grade> grades, unsigned short daysMissing) {
	strcpy_s(this->name, name.c_str());

	this->grades = grades;

	this->daysMissed = daysMissing;
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
