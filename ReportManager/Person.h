#pragma once
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
	Student(Gender gender, std::string name, tm birthDate, float height, float weight, std::vector<Subject> subjects);
	Student(Person person, std::vector<Subject> subjects);
	Student(std::string id, char gender, std::string name, std::string birthDate, std::string height, std::string weight, std::vector<Subject> subjects);


	unsigned short getId();

	Subject getSubject(unsigned short index);
	std::vector<Subject> getSubjects();

	double Average();

	//Generate unique id
	void GenerateID();

private:
	//Unique identifier of each person
	unsigned short id;

	//Seven subjects of the student
	std::vector<Subject> subjects;
};
