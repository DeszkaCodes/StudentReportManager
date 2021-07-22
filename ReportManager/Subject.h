#pragma once
#include <vector>
#include <string>

//SubjectTypes to make creating subjects easier
enum class SubjectType : short {
	Math = 1,
	PE = 2,
	History = 3,
	Grammar = 4,
	Art = 5,
	RE = 6,
	IT = 7,
	Error = 404
};


class Subject
{
public:
	Subject(SubjectType _name, std::vector<unsigned short> grades);
	Subject(SubjectType _name, std::string grades);

	//Two ways to get the name of the subject
	std::string getNameStr();
	SubjectType getNameType();


	/*The grades are stored in unsigned short vectors
	because of their flexibility and low memory usage.*/
	std::vector<unsigned short> grades;

	//Calculate the average of the grades for later analysis
	double GetMean();

	//Convert grades vector into a string, which can be written into the files
	std::string GradesToString();

	//Convert a string into an unsigned short vector
	static std::vector<unsigned short> StringToGrades(std::string string, char seperator = '-');

private:
	const SubjectType name;
};
