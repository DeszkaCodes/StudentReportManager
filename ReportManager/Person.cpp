#include "Person.h"

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

tm Person::getBirthDate(){
	return this->birthDate;
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

unsigned short Student::getId(){
	return this->id;
}

Subject Student::getSubject(unsigned short index){
	return this->subjects[index];
}

Subject* Student::getSubjects(){
	return this->subjects;
}

double Student::Average(){
	double sum = 0;

	for (unsigned short i = 0; i < 7; i++)
	{
		sum += this->subjects[i].GetMean();
	}

	return sum / 7;
}

void Student::GenerateID(){

}
