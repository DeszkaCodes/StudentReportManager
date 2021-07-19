#include "Subject.h"

Subject::Subject(std::string name, std::vector<Grade> grades) {
	strcpy(this->name, name.c_str());

	this->grades = grades;
}

std::string Subject::getName() {
	return this->name;
}

float Subject::GetMean() {
	float sum = std::accumulate(grades.begin(), grades.end(),
		decltype(grades)::value_type(0));

	return sum / grades.size();
}
