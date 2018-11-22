#include "system.h"
#include<vector>
#include<utility>

using namespace std;


System :: System() {

	mass = 0.02;
	timeStep = 0.02;
	initialSpacing = 0.02;
	
	//initialise particle, custom
	vector<Particle> particles; 

	

	float x_start = -0.2, x_end = 0.2, x_step=0.02;
	float y_start = 5.2, y_end = 4.8, y_step = 0.02;
	
	while(x_start < x_end) {
		y_start = 5.2;
		while(y_start > y_end) {	
			Particle p(mass, 0);
			p.setPosition(make_pair(x_start, y_start));
			p.setKernelLength(2*initialSpacing);
			p.setVelocity(make_pair(0, 0));
			particles.push_back(p);
			y_start -= y_step;		
		}
		x_start += x_step;
	}
	
	//array of horizontal particles for base

	float x_1 = -1, x_2=1;
	y_start = 5, y_end = 0, y_step = 0.02;
	//set boundary
        
	B.xmin = -2;
	B.xmax = 2;
	B.ymin = 0;
	B.ymax = 10;

	
	while(y_start > y_end) {
		Particle p1(mass, 1);
		p1.setPosition(make_pair(x_1, y_start));
		particles.push_back(p1);

		Particle p2(mass, 1);
		p2.setPosition(make_pair(x_2, y_start));
		particles.push_back(p2);
		y_start -= y_step;
	}

	//array of vertical particles on both sides
	
	float y=0;
	x_start = -1, x_end=1, x_step=0.02;

	while(x_start<x_end) {
		Particle p(mass, 1);
		p.setPosition(make_pair(x_start, y));
		particles.push_back(p);
		x_start += x_step;
	}

	this->particles = particles; 

}


vector<Particle> System :: getParticles() {
	return particles;
}

float System :: getTimeStep() {
	return timeStep;
}

float System :: getInitialSpacing() {
	return initialSpacing;
}

float System :: getD() {
	return D;
}

void System :: setParticles(vector<Particle> p) {
	this->particles = p;
}

Boundary System :: getBoundary() {
	return this->B;
}

void System :: setBoundary(Boundary B) {
	this->B = B;
}

/*
int main() {
	System s;
	Utility util;
	vector<Particle> p = s.getParticles();
	string filename = "test3.txt";
	cout << p.size();
	util.saveParticleData(p, filename);
	
}
*/
