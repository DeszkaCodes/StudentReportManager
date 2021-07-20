#include "Student.h"
#include "IOSystem.h"
#include <time.h>
#include <limits>

Student::Student(std::string name, unsigned short heightCm, float weightKg, Subject subjects[7]) {
	strcpy_s(this->name, name.c_str());

	this->height = heightCm;
	this->weight = weightKg;

	this->subjectPointer = subjects;

	this->RegenID();
}

Student::Student(unsigned short id, std::string name, unsigned short heightCm, float weightKg, Subject subjects[7]) {
	strcpy_s(this->name, name.c_str());

	this->height = heightCm;
	this->weight = weightKg;

	this->subjectPointer = subjects;

	this->id = id;
}

Student::Student(std::string name, unsigned short heightCm, float weightKg) {
	strcpy_s(this->name, name.c_str());

	this->height = heightCm;
	this->weight = weightKg;

	this->RegenID();
}

std::string Student::getName() {
	return this->name;
}

unsigned short Student::getHeight() {
	return this->height;
}

float Student::getWeight() {
	return this->weight;
}

unsigned short Student::getId() {
	return this->id;
}

float Student::Average() {
	float sum = 0;

	for (unsigned short i = 0; i < 7; i++) {
		sum += this->subjectPointer[i].GetMean();
	}

	return sum / 7;
}

unsigned short Student::DaysMissed() {
	unsigned short sum = 0;

	for (unsigned short i = 0; i < 7; i++) {
		sum += this->subjectPointer[i].daysMissed;
	}

	return sum;
}

void Student::RegenID() {
	srand(time(NULL));

	unsigned short id = rand() % USHRT_MAX;
	
	while (CheckID(id, "students.csv")) {
		id = rand() % USHRT_MAX;
	}

	this->id = id;
}

Subject* Student::getSubjects() {
	return this->subjectPointer;
}

Subject Student::getSubject(unsigned short index) {
	return this->subjectPointer[index];
}