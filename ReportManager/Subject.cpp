#include "Subject.h"
#include <vector>
#include <string>
#include <sstream>


//Use member initializer to change the name constant
Subject::Subject(Type _name, std::vector<unsigned short> grades) :
	name(_name) {
	this->grades = grades;
}
Subject::Subject(Type _name, std::string grades) :
	name(_name) {
	this->grades = *Subject::StringToGrades(grades);
}


//Non elegant way to get the name as a string
std::string Subject::getNameStr() {
	switch (this->name) {
	case Type::Math:
		return "Math";
		break;
	case Type::PE:
		return "P.E.";
		break;
	case Type::History:
		return "History";
		break;
	case Type::Grammar:
		return "Grammar";
		break;
	case Type::Art:
		return "Art";
		break;
	case Type::RE:
		return "R.E.";
		break;
	case Type::IT:
		return "I.T.";
		break;
	default:
		return "Error";
	}
}
Type Subject::getNameType() {
	return this->name;
}


double Subject::GetMean() {
	unsigned int sum = 0;

	for (size_t i = 0; i < this->grades.size(); i++)
	{
		sum += this->grades[i];
	}

	return sum / this->grades.size();
}


std::string* Subject::GradesToString() {
	std::string gradesStr;

	for (size_t i = 0; i < this->grades.size(); i++)
	{
		if (i != 0)
			gradesStr = gradesStr.append("-");

		gradesStr = gradesStr.append(std::to_string(this->grades[i]));
	}

	return &gradesStr;
}


//String will be seperated by the seperator
std::vector<unsigned short>* Subject::StringToGrades(std::string string, char seperator) {

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

	return &grades;
}