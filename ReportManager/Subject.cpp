#include "Subject.h"
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

//Use member initializer to change the name constant
Subject::Subject(SubjectType _name, std::vector<unsigned short> grades) :
	name(_name) {
	this->grades = grades;
}
Subject::Subject(SubjectType _name, std::string grades) :
	name(_name) {
	this->grades = Subject::StringToGrades(grades);
}


//Non elegant way to get the name as a string
std::string Subject::getNameStr() {
	switch (this->name) {
	case SubjectType::Math:
		return "Math";
		break;
	case SubjectType::PE:
		return "P.E.";
		break;
	case SubjectType::History:
		return "History";
		break;
	case SubjectType::Grammar:
		return "Grammar";
		break;
	case SubjectType::Art:
		return "Art";
		break;
	case SubjectType::RE:
		return "R.E.";
		break;
	case SubjectType::IT:
		return "I.T.";
		break;
	default:
		return "Error";
	}
}
SubjectType Subject::getNameType() {
	return this->name;
}


double Subject::GetMean() {
	unsigned int sum = std::accumulate(this->grades.begin(), this->grades.end(),
		decltype(this->grades)::value_type(0));

	return sum / this->grades.size();
}


std::string Subject::GradesToString() {
	std::string gradesStr;

	for (size_t i = 0; i < this->grades.size(); i++)
	{
		if (i != 0)
			gradesStr = gradesStr.append("-");

		gradesStr = gradesStr.append(std::to_string(this->grades[i]));
	}

	return gradesStr;
}


//String will be seperated by the seperator
std::vector<unsigned short> Subject::StringToGrades(std::string string, char seperator) {

	std::vector<unsigned short> grades;

	std::string grade;

	std::stringstream s(string);

	while (std::getline(s, grade, seperator)) {
		try {
			grades.push_back(std::stoi(grade));
		}
		catch (...) {
			continue;
		}
	}

	return grades;
}