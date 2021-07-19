#include "Subject.h"

Subject::Subject(std::string name, std::vector<Grade> grades, unsigned short daysMissing = 0) {
	strcpy(this->name, name.c_str());

	this->grades = grades;

	this->daysMissed = daysMissing;
}

std::string Subject::getName() {
	return this->name;
}

float Subject::GetMean() {
	//Calculates sum of grades vector
	float sum = std::accumulate(grades.begin(), grades.end(),
		decltype(grades)::value_type(0));

	return sum / grades.size();
}
