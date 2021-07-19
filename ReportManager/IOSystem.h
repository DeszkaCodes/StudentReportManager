#include "Student.h"

#ifndef IOSystem_H
#define IOSystem_H

namespace StudentIO {
	void WriteData(Student student);

	Student* ReadAllData();

	//Returns true if the given ID already exists
	bool CheckID(unsigned short id);
};

#endif // !IOSystem_H
