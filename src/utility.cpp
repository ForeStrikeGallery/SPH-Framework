#include<vector>
#include<cmath>
#include<fstream>
#include "utility.h"

void Utility :: saveParticleData(vector<Particle> &p) {
        std :: ofstream file;
        file.open("data.txt", std :: ios_base :: app);

        for (int i=0; i< p.size(); i++) {
                file<< p[i].getPosition().first << " " << p[i].getPosition().second<<endl;
        }
        file<< "end of time" << endl;

        file.close();
}



float Utility :: calcEuclideanDistance(const pair<float, float> &pos1, const pair<float, float> &pos2 ) {

        return sqrt(pow(pos1.first-pos2.first, 2) + pow(pos1.second-pos2.second, 2));
        
}

