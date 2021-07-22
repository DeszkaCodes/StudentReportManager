#include "Person.h"
#include "IOSystem.h"
#include <ctime>
#include <sstream>
#include <time.h>
#include <random>
#include <limits>

//Person class
Person::Person(Gender gender, std::string name, tm birthDate, float height, float weight) :
	gender(gender), name(name), birthDate(birthDate) {
	this->height = height;
	this->weight = weight;
}
#pragma warning( push )
#pragma warning( disable : 26495 )
Person::Person(Gender gender, std::string name, tm birthDate) :
	gender(gender), name(name), birthDate(birthDate) {};

#pragma warning( pop )


std::string Person::getGenderStr() {
	switch (this->gender) {
	case Gender::Male:
		return "Male";
		break;
	case Gender::Female:
		return "Female";
		break;
	case Gender::Other:
		return "Other";
		break;
	default:
		return "Error";
	}
}
Gender Person::getGender() {
	return this->gender;
}
unsigned char Person::getGenderChar() {
	return (unsigned char)this->gender;
}

std::string Person::getName() {
	return this->name;
}

tm Person::getBirthDate() {
	return this->birthDate;
}

std::string Person::getBirthString() {
	std::string date;

	date.append(std::to_string(this->birthDate.tm_year + 1990) + '-');
	date.append(std::to_string(this->birthDate.tm_mon + 1) + '-');
	date.append(std::to_string(this->birthDate.tm_mday));

	return date;
}

//Date format YYYY-MM-DD
tm Person::StringToDate(std::string rawDate) {

	std::string data;

	unsigned short arrDate[3]{ 0,0,0 };

	std::stringstream s(rawDate);

	unsigned short counter = 0;

	while (std::getline(s, data, '-')) {
		arrDate[counter] = std::stoi(data);

		counter++;
	}

	tm date;

	date.tm_year = arrDate[0] - 1990;
	date.tm_mon = arrDate[1] - 1;
	date.tm_mday = arrDate[2];

	return date;
}


//Student class
Student::Student(Gender gender, std::string name, tm birthDate, float height, float weight, Subject subjects[7]) :
	Person(gender, name, birthDate) {
	this->height = height;
	this->weight = weight;

	this->subjects = subjects;

	GenerateID();
}

Student::Student(Person person, Subject subjects[7]) :
	Person(person.getGender(), person.getName(), person.getBirthDate()) {
	this->weight = person.weight;
	this->height = person.height;

	this->subjects = subjects;

	GenerateID();
}

Student::Student(std::string id, char gender, std::string name, std::string birthDate, std::string height, std::string weight, Subject subjects[7]) :
	Person((Gender)gender, name, Person::StringToDate(birthDate)) {
	this->height = std::stof(height);
	this->weight = std::stof(weight);

	this->subjects = subjects;

	this->id = std::stoi(id);
}


unsigned short Student::getId() {
	return this->id;
}

Subject Student::getSubject(unsigned short index) {
	return this->subjects[index];
}

Subject* Student::getSubjects() {
	return this->subjects;
}

double Student::Average() {
	double sum = 0;

	for (unsigned short i = 0; i < 7; i++)
	{
		sum += this->subjects[i].GetMean();
	}

	return sum / 7;
}

void Student::GenerateID() {
	#pragma warning( push )
	#pragma warning( disable : 4244 )
	srand(time(NULL));
	#pragma warning( pop )

	unsigned short tempId;

	do {
		tempId = rand() % USHRT_MAX;
	} while (IDRes::CheckID(tempId, "students").getFound());

	this->id = tempId;
}
