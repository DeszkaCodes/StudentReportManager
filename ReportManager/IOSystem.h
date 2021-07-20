#include "Student.h"

#ifndef IOSystem_H
#define IOSystem_H

bool CheckID(unsigned short id, std::string file);

namespace StudentIO {
	void WriteData(Student student);

};

namespace GradeIO {
	void WriteData(Student student);
}

#endif // !IOSystem_H
