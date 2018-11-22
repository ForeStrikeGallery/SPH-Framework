#include "utility.h"
#include "kernel.h"
#include "force.h"
#include<vector>
#include<cmath>

using namespace std;

Kernel K;
//Utility util;

pair<float, float> Force :: pressureForce (Particle &p, vector<Particle> &neighbours) {

	float pr1 = p.getPressure();
	pair<float, float> p1 = p.getPosition();
	float rho1 = p.getDensity();
	float m1 = p.getMass();
	float h = p.getKernelLength();

	pair<float, float> pressureForce = make_pair(0, 0);

	for (int i=0; i<neighbours.size(); i++) {
		if (neighbours[i].getType() == 1)
			continue;
		float pr2 = neighbours[i].getPressure();
		pair<float, float> p2 = neighbours[i].getPosition();
		float rho2 = neighbours[i].getDensity();
		float m2 = neighbours[i].getMass();
		pair<float, float> W = K.W_spiky_grad(p1, p2, h);
		float f_x = m2 * ( pr1/pow(rho1, 2) + pr2/pow(rho2, 2) ) * W.first;
		float f_y = m2 * ( pr1/pow(rho1, 2) + pr2/pow(rho2, 2) ) * W.second;
		pressureForce.first += f_x;
		pressureForce.second += f_y;
	}

	pressureForce.first *= -m1;
	pressureForce.second *= -m1;

	return pressureForce;
}

pair<float, float> Force :: viscousForce (Particle &p, vector<Particle> &neighbours) {

	float coeffVisc = 3.5;
	pair<float, float> u1 = p.getVelocity();
	pair<float, float> r1 = p.getPosition();
	float m = p.getMass();
	float h = p.getKernelLength();

	pair<float, float> viscousForce = make_pair(0, 0);
	
	for (int i=0; i<neighbours.size(); i++) {
		if (neighbours[i].getType() == 1)
			continue;

		float rho2 = neighbours[i].getDensity();
		pair<float, float> u2 = neighbours[i].getVelocity();
		pair<float, float> r2 = neighbours[i].getPosition();
		float W = K.W_visc_lapl(u1, u2, h);
		float f_x = (u2.first - u1.first) * m * W/rho2;
		float f_y = (u2.second - u1.second) * m * W/rho2;
		viscousForce.first += f_x;
		viscousForce.second + f_y;		
	}

	viscousForce.first *= coeffVisc;
	viscousForce.second *= coeffVisc;

	return viscousForce;
}



pair<float, float> Force :: gravityForce(Particle &p) {
	
	float g = 9.81;
	return make_pair(0.0, -p.getDensity()*g);
}

pair<float, float> Force :: surfaceTensionForce(Particle &p, vector<Particle> &neighbours) {
	return make_pair(0, 0);
}

pair<float, float> Force :: boundaryForce(Particle &p, vector<Particle> &neighbours, float r0, float D) {

	Utility util;	
	float p1 = 4;
	float p2 = 2;
	pair<float, float> r1 = p.getPosition();
	
	pair<float, float> boundaryForce = make_pair(0.0, 0.0);
	
	int count =0;
	for (int i=0; i<neighbours.size(); i++) {
		if (neighbours[i].getType() == 0)
			continue;
		
		pair<float, float> r2 = neighbours[i].getPosition();		
		pair<float, float> r = make_pair(r1.first - r2.first, r1.second - r2.second);
		if (util.mod(r) > r0)
			continue;
		count++;
		cout << r2.first <<" "<<r2.second << endl;
		float f_x = D * (pow(r0/r.first, p1) + pow(r0/r.first, p2)) * (r2.first - r1.first)/pow(util.mod(r), 2);
		float f_y = D * (pow(r0/r.second, p1) + pow(r0/r.second, p2)) * (r2.first - r1.first)/pow(util.mod(r), 2);
		cout << f_x <<" " << util.mod(r)<<endl;
		boundaryForce.first += f_x;
		boundaryForce.second += f_y; 
	}	
	cout << "count: " << count <<" r0: " << r0<< endl;
	return boundaryForce;
}




