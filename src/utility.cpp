#include<vector>
#include<cmath>
#include<fstream>
#include<iostream>
#include "utility.h"
using namespace std;

void Utility :: saveParticleData(vector<Particle> &p, string filename) {
//        cout << "Utility Ethi";
	std :: ofstream file;
        //file.open(filename.c_str() , std :: ios_base :: app);
	file.open(filename.c_str());
        for (int i=0; i< p.size(); i++) {
                file<< p[i].getPosition().first << " " << p[i].getPosition().second<<" "<<p[i].getType()<<endl;
	//	cout<< p[i].getPosition().first << " " << p[i].getPosition().second<<" "<<p[i].getType()<<endl;
        }
        

        file.close();
}



float Utility :: calcEuclideanDistance(const pair<float, float> &pos1, const pair<float, float> &pos2 ) {

        return sqrt(pow(pos1.first-pos2.first, 2) + pow(pos1.second-pos2.second, 2));
        
}

float Utility :: mod(pair<float, float> &pos1) {
	return sqrt(pow(pos1.first, 2) + pow(pos1.second, 2));
}

pair<float, float> Utility :: add(pair<float, float> r1, pair<float, float> r2) {

	return make_pair(r1.first + r2.first, r1.second + r2.second);
}

pair<float, float> Utility :: subtract(pair<float, float> r1, pair<float, float> r2) {
	return make_pair(r1.first - r2.first, r1.second - r2.second);
}
