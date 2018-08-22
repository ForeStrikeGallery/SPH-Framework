#ifndef INTEGRATOR_H
#define INTEGRATOR_H
#include<vector>
#include "particle.h"

using namespace std;

class Integrator {

public:
	void leapFrog(Particle &p, float timeStep);
};

#endif
