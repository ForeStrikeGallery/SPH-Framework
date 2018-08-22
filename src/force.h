#ifndef FORCE_H
#define FORCE_H

#include "particle.h"
#include<vector>
#include<cmath>
using namespace std;
class Force {

public:
	pair<float, float> pressureForce(Particle &p, vector<Particle> &neighbours);
	pair<float, float> viscousForce(Particle &p, vector<Particle> &neighbours);
	pair<float, float> gravityForce(Particle &p);
	pair<float, float> surfaceTensionForce(Particle &p, vector<Particle> &neighbours);
	pair<float, float> boundaryForce(Particle &p, vector<Particle> &neighbours, float initialSpacing, float D);

};

#endif

