#include "Student.h"

#ifndef IOSystem_H
#define IOSystem_H

bool CheckID(unsigned short id, std::string fileName);

namespace StudentIO {
	void WriteData(Student student);

	std::vector<Student> ReadAll();
};

namespace GradeIO {
	void WriteData(Student student);
	Subject* ReadGrade(unsigned short id);
}

#endif // !IOSystem_H
