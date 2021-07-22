#include "IOSystem.h"


//IDIO namespace


//IDRes class
IDIO::IDRes::IDRes(bool isFound, unsigned int row, std::string fileName) :
	found(isFound), row(row), fileName(fileName) {};
bool IDIO::IDRes::getFound() {
	return this->found;
}
unsigned int IDIO::IDRes::getRow() {
	return this->row;
}
std::string IDIO::IDRes::getFileName() {
	return this->fileName;
}
//IDRes end

IDIO::IDRes IDIO::CheckID(unsigned short id, std::string csvName) {
	std::ifstream stream("Files/" + csvName + ".csv", std::ios::in);

	if (stream.is_open()) {
		
		unsigned short readId;

		std::string line, column;

		unsigned int row = 0;

		while (getline(stream, line)) {
			row++;

			if (line[0] == '*')
				continue;

			std::stringstream s(line);

			getline(s, column, ',');

			readId = std::stoi(column);

			if (readId == id) {
				stream.close();

				return IDRes(true, row, csvName);
			}
		}

		stream.close();

		return IDRes(false);
	}
}


//IDIO end