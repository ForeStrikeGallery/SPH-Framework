#ifndef SYSTEM_H
#define SYSTEM_H
#include<vector>
#include "utility.h"
using namespace std;

class System {
	
	float mass;
	float timeStep;
	float totalParticles;
	vector<Particle> particles;
	float initialSpacing;
	float D;
	
		
	
public:
	System();
	vector<Particle> getParticles();
	float getTimeStep();
	float getInitialSpacing();
	float getD();
	
};


#endif
