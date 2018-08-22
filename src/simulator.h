#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "system.h"
#include<string>

class Simulator {
	System s;
public:
	Simulator();
	void runSPH();
	void saveDataToFile(string fileName);

};

#endif
