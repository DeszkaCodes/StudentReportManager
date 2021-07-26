#pragma once
#include <vector>
#include <string>

class Subject
{
public:
	Subject(std::string _name, std::vector<unsigned short> grades);
	Subject(std::string _name, std::string grades);


	//Two ways to get the name of the subject
	std::string getName();


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
	std::string name;
};
