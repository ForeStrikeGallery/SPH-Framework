#ifndef PARTICLE_H
#define PARTICLE_H

#include<vector>
#include<utility>
using namespace std;


class Particle {

        float rho, m, h;
        pair<float, float> position;
        pair<float, float> velocity;
        pair<float, float> force;
public:
        Particle(float);
        void setDensity(float);
        void setPosition(pair<float, float>);
        void setVelocity(pair<float, float>);
        void setForce(pair<float, float>);
	void setKernelLength(float);

        float getMass();
        float getDensity();
        pair<float, float> getPosition();
        pair<float, float> getVelocity();
        pair<float, float> getForce();
	float getKernelLength();  

};

#endif
