#pragma once
#include <string>
#include <ctime>
#include <sstream>
#include "Subject.h"

enum class Gender : unsigned char {
	Male = 'm',
	Female = 'f',
	Other = 'o'
};

class Person {
public:
	//Constructors
	Person(Gender gender, std::string name, tm birthDate, float height, float weight);


	//Get methods
	std::string getGenderStr();
	Gender getGender();
	unsigned char getGenderChar();

	std::string getName();
	tm getBirthDate();
	std::string getBirthString();


	//Variables
	float height; //Meter
	float weight; //Kilogramm

	//Other methods
	static tm StringToDate(std::string rawDate);

protected:
	const Gender gender;
	const std::string name;
	const tm birthDate;

	//Workaround for initializing const data in child
	Person(Gender gender, std::string name, tm birthDate);
};

class Student : public Person {
public:
	Student(Gender gender, std::string name, tm birthDate, float height, float weight, Subject subjects[7]);
	Student(Person person, Subject subjects[7]);

	unsigned short getId();

	Subject getSubject(unsigned short index);
	Subject* getSubjects();

	double Average();

	//Generate unique id
	void GenerateID(); //NEEDS IMPLEMENTATION

private:
	//Unique identifier of each person
	unsigned short id;

	//Seven subjects of the student
	Subject* subjects = NULL;
};