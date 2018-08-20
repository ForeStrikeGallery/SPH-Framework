#include<vector>
#include<iostream>
#include<cmath>
#include "particle.h"
using namespace std;
#ifndef UTILITY_H
#define UTILITY_H

class Utility {
public:
	void saveParticleData(vector<Particle> &p);
	float calcEuclideanDistance(const pair<float, float> &pos1, const pair<float, float> &pos2);
};

#endif
