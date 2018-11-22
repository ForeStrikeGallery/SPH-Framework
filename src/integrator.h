#ifndef INTEGRATOR_H
#define INTEGRATOR_H
#include<vector>
#include "system.h"

using namespace std;

class Integrator {

public:
	void leapFrog(Particle &p, float timeStep, Boundary B);
};

#endif
