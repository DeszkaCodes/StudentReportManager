#include "Subject.h"
#include <sstream>

Subject::Subject(SubjectName name, std::vector<short> grades) {
	this->name = name;

	this->grades = grades;
}

std::string Subject::getName() {
	switch (this->name) {
	case SubjectName::Math:
		return "Math";
		break;
	case SubjectName::PE:
		return "P.E.";
		break;
	case SubjectName::History:
		return "History";
		break;
	case SubjectName::Grammar:
		return "Grammar";
		break;
	case SubjectName::Art:
		return "Art";
		break;
	case SubjectName::RE:
		return "R.E.";
		break;
	case SubjectName::IT:
		return "I.T.";
		break;
	default:
		return "Error";
	}
}

float Subject::GetMean() {
	//Calculates sum of grades vector
	int sum = 0;
	unsigned short size = this->grades.size();

	for(unsigned short i = 0; i < size; i++)
	{
		sum += grades[i];
	}

	return (float)sum / size;
}

std::string Subject::StringifyGrades() {
	std::string grades = "";

	for (unsigned short i = 0; i < this->grades.size(); i++)
	{
		grades += std::to_string(this->grades[i]);

		if (i != this->grades.size()-1)
			grades += '-';
	}

	return grades;
}

std::vector<short> Subject::StringToGrade(std::string rawGrades) {
	std::string rawGrade;

	std::vector<short> grades;

	std::stringstream s(rawGrades);

	while (std::getline(s, rawGrade, '-')) {
		
		short grade = std::stoi(rawGrade);

		grades.push_back(grade);
	}

	return grades;
}