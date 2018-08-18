#include<vector>
#include<utility>
using namespace std;

class Particle {

	float rho, m;
	pair<float, float> position;
	pair<float, float> velocity;
	pair<float, float> force;
public:
	Particle(float);
	void setDensity(float);
	void setPosition(pair<float, float>);
	void setVelocity(pair<float, float>);
	void setForce(pair<float, float>);

	float getMass();
	float getDensity();
	pair<float, float> getPosition();
	pair<float, float> getVelocity();
	pair<float, float> getForce();	

};


class Particles {

	vector<Particle> particles;

public:
	Particles();
	Particle findNearestNeighbour(Particle);
	vector<Particle> getParticles();	
		
};


class Simulator {

	public:
		void initialiseParticles(Particles);
		void calculateForces(Particles);
		void timeIntegrate(Particles);
		void saveData(char* filename);
};
