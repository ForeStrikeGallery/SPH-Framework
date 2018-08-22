#include "simulator.h"
#include "nnsearch.h"
#include "force.h"
#include "integrator.h"
#include "kernel.h"
#include<vector>

using namespace std;

Simulator :: Simulator() {

	
}

void Simulator :: saveDataToFile(string filename) {
	Utility util;	
	vector<Particle> p = s.getParticles();
	util.saveParticleData(p, filename);	
}

void Simulator :: runSPH() {

	NearestNeighbourSearch NN;
        Force F;
	Kernel K;
	Integrator I;
	Utility util;

	// This is the main simulation loop

	vector<Particle> p = s.getParticles();
	vector< vector<int> > neighbour_list = NN.search(p, 0);
	for (int i=0; i<p.size(); i++) {
		/* Initialise */
		p[i].setDensity(0);
		p[i].setKernelLength(s.getInitialSpacing()*2);
		pair<float, float> f = F.gravityForce(p[i]);
		p[i].setForce(f);
	
		vector<int> neighbours = neighbour_list[i];
		float rho = 0;
		pair<float, float> r1 = p[i].getPosition();
		float h = p[i].getKernelLength();
		
		/* Accumulate density */ 
		for (int j=0; j<neighbours.size(); j++) {
			float m = p[neighbours[j]].getMass();
			pair<float, float> r2 = p[neighbours[j]].getPosition();
			rho += m*K.W(r1, r2 , h);
		}
			
		p[i].setDensity(rho);

		/* Calculate pressure */
		float Pr = 34; //some constant
		p[i].setPressure(Pr);


		/* Accumulate forces */
		f = p[i].getForce();
		vector<Particle> pNeighbours;
		for (int j=0; j<neighbours.size(); j++) {
			pNeighbours.push_back(p[neighbours[j]]);
		}

		pair<float, float> gForce = F.gravityForce(p[i]);
		pair<float, float> pForce = F.pressureForce(p[i], pNeighbours);
		pair<float, float> vForce = F.viscousForce(p[i], pNeighbours);
		pair<float, float> sForce = F.surfaceTensionForce(p[i], pNeighbours);
		pair<float, float> bForce = F.boundaryForce(p[i], pNeighbours, s.getInitialSpacing(), s.getD());

		cout << "gForce " << gForce.first <<" " << gForce.second<<endl; 
		f = util.add(f, gForce);
		f = util.add(f, pForce);
		f = util.add(f, vForce);
		f = util.add(f, sForce);
		f = util.add(f, bForce);
		
		I.leapFrog(p[i], s.getTimeStep());
		
	}
}




