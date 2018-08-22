#include<vector>
#include<iostream>
#include<cmath>
#include<string>
#include "particle.h"
using namespace std;
#ifndef UTILITY_H
#define UTILITY_H

class Utility {
public:
	void saveParticleData(vector<Particle> &p, string filename);
	float calcEuclideanDistance(const pair<float, float> &pos1, const pair<float, float> &pos2);
	float mod(pair<float, float>&);
	pair<float, float> add(pair<float, float>, pair<float, float>);
	pair<float, float> subtract(pair<float, float>, pair<float, float>);
};

#endif
