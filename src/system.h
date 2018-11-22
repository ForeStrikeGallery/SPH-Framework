#ifndef SYSTEM_H
#define SYSTEM_H
#include<vector>
#include "utility.h"
using namespace std;

struct Boundary {
	int xmin;
	int ymin;
	int xmax;
	int ymax;
};

class System {
	
	float mass;
	float timeStep;
	float totalParticles;
	vector<Particle> particles;
	float initialSpacing;
	float D;
	Boundary B;
	
		
public:
	System();
	vector<Particle> getParticles();
	Boundary getBoundary();
	float getTimeStep();
	float getInitialSpacing();
	float getD();
	void setParticles(vector<Particle>);
	void setBoundary(Boundary B);	
};


#endif
