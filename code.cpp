#include<vector>
#include<iostream>
#include<utility>
#include<cmath>
#include<algorithm>
#include<time.h>
#include<cstdlib>
#include<fstream>

using namespace std;

//srand(time(NULL));
#define MASS 1

class Particle {
	float m, rho;
	pair<float, float> position;
	pair<float, float> velocity;
	pair<float, float> force;

public: 
	Particle(float);
	float getDensity();
	pair<float, float> getPosition();
	pair<float, float> getVelocity();
	pair<float, float> getForce();

	void setDensity(float rho);
	void setPosition(pair<float, float>);
	void setVelocity(pair<float, float>);
	void setForce(pair<float, float>);
	
};

Particle :: Particle(float m) {
	this->m = m;
}

float Particle :: getDensity() {
	return rho;
}

pair<float, float> Particle :: getPosition() {
	return position;
}

pair<float, float> Particle :: getVelocity() {
	return velocity;
}

pair<float, float> Particle :: getForce() {
	return force;
}

void Particle :: setDensity(float rho) {
	this->rho = rho;
}

void Particle :: setPosition(pair<float, float> position) {
	this->position = position;
}

void Particle :: setVelocity(pair<float, float> velocity) {
	this->velocity = velocity;
}

void Particle :: setForce(pair<float, float> force) {
	this->force = force;
}


float calcEuclideanDistance(const pair<float, float> &pos1, const pair<float, float> &pos2 ) {

	return sqrt(pow(pos1.first-pos2.first, 2) + pow(pos1.second-pos2.second, 2));
	
}

float W(pair<float, float> &pos1, pair<float, float> &pos2, float h) {
	float dist = calcEuclideanDistance(pos1, pos2);
	if (dist > h)
		return 0;
	else
		return pow(pow(h, 2) - pow(dist, 2), 3)*pow(h, -9);
	
}

vector< vector<int> >  nearestNeighbourSearch(const vector<Particle> &p, float h) {

	srand(time(NULL));
	vector< vector<int> > neighbours;
	for (vector<Particle> :: const_iterator itr = p.begin(); itr != p.end(); itr++) {
		Particle node = *itr;
		vector< pair<float, int> > distance_from_node;
		pair<float, float> node_pos = node.getPosition();
		

		for (vector<Particle> :: const_iterator itr1 = p.begin(); itr1 != p.end(); itr1++) {
			Particle part = *itr1;
			pair<float, float> p_pos = part.getPosition();
			float distance = calcEuclideanDistance(node_pos, p_pos);
			int inner_index = itr1 - p.begin();
			distance_from_node.push_back(make_pair(distance, inner_index));
			
		}

		sort(distance_from_node.begin(), distance_from_node.end());
		vector<int> nearest_neighbours;
		int i=0;
		while(true) {
			float dist = distance_from_node[i++].first;
			if ( dist > h )
				break;
			else {
				nearest_neighbours.push_back(dist);		
			}	
		}

		neighbours.push_back(nearest_neighbours);
	}

	return neighbours;
} 


void sph(float h, vector<Particle> &p, float dt) {
	srand(time(NULL));
	cout << "Calculating all nearest neighbours"<<endl;
	vector< vector<int> > neighbours = nearestNeighbourSearch(p, h);
	
	for (vector<Particle>::iterator itr=p.begin(); itr != p.end(); itr++) {
		//Initialise particles
	
		Particle part = *itr;
		part.setDensity(0);
		pair<float, float> pos1 = part.getPosition();
		float rho = part.getDensity();
		vector<int> neighb = neighbours[itr-p.begin()];
		
		//Update Density
		for (int index=0; index < neighb.size(); index++) {
			Particle neigh_particle = neighb[index];
			pair<float, float> pos2 = neigh_particle.getPosition();
			rho += MASS * W(pos1, pos2, h);	
		}

		part.setDensity(rho);
		
		//Update forces
		
		for (int index=0; index> neighb.size(); index++) {
				
		}		
	}

	// Time step integration
	for (int i=0; i<p.size(); i++) {
		pair<float, float> velocity = p[i].getVelocity();
		pair<float, float> position = p[i].getPosition();	
		pair<float, float> force = p[i].getForce();
	
		velocity.first += velocity.first + dt*force.first/MASS;
		velocity.second += velocity.second + dt*force.second/MASS;

		position.first += position.first + dt*velocity.first;
		position.second += position.second + dt*velocity.second;

		p[i].setVelocity(velocity);
		p[i].setPosition(position);
	}

	
	
}

void setInitialCondition(vector<Particle> &p) {
	for (int i=0; i< p.size(); i++) 
		p[i].setPosition(make_pair(rand()%10, rand()%10));
}

void saveParticleData(vector<Particle> &p) {
	std :: ofstream file;
	file.open("data.txt", std :: ios_base :: app);

	for (int i=0; i< p.size(); i++) {
		file<< p[i].getPosition().first << " " << p[i].getPosition().second<<endl; 	
	}
	file<< "end of time" << endl;

	file.close();
}

int main() {

	
	vector<Particle> p;
	for (int i=0; i<1000; i++) 
		p.push_back(Particle(1));
	setInitialCondition(p);
	float h = 0.1;
	float dt;

	for (int i=0; i<100; i++) {
		sph(h, p, dt);
		saveParticleData(p);	
	}
		
	return 0;	
}


