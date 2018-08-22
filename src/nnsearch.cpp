#include<utility>
#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#include<cstdlib>
#include<algorithm>
#include "nnsearch.h"
using namespace std;

// Global utility object

Utility util;

NearestNeighbourSearch :: NearestNeighbourSearch() {
//	cout << "nnsearch initialised ";
}

vector<vector <int> > NearestNeighbourSearch :: search ( vector<Particle> &p, \
					  int type=0 ) {
	switch(type) {
		case 0:
			return allPairsSearch(p);
		case 1:
			return cellIndexing(p);
		case 2:
			return spatialHashing(p);
		case 3:
			return cellSplitting(p);
		default: 
			return allPairsSearch(p);
	}		

	
} 

vector< vector<int> >  NearestNeighbourSearch :: allPairsSearch(vector<Particle> &p) {

        srand(time(NULL));
        vector< vector<int> > neighbours;
        for (vector<Particle> :: iterator itr = p.begin(); itr != p.end(); itr++) {
                Particle node = *itr;
                vector< pair<float, int> > distance_from_node;
                pair<float, float> node_pos = node.getPosition();


                for (vector<Particle> :: iterator itr1 = p.begin(); itr1 != p.end(); itr1++) {
                        Particle part = *itr1;
                        pair<float, float> p_pos = part.getPosition();
                        float distance = util.calcEuclideanDistance(node_pos, p_pos);
                        int inner_index = itr1 - p.begin();
                        distance_from_node.push_back(make_pair(distance, inner_index));

                }

                sort(distance_from_node.begin(), distance_from_node.end());
                vector<int> nearest_neighbours;
                int i=0;
		float h = node.getKernelLength();
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

vector< vector<int> > NearestNeighbourSearch :: cellIndexing ( vector<Particle> &p ) {
	vector< vector<int> > neighbours;
	return neighbours;
} 


vector< vector<int> > NearestNeighbourSearch :: spatialHashing ( vector<Particle> &p ) {
	vector< vector<int> > neighbours;
	return neighbours;
}

vector< vector<int> > NearestNeighbourSearch :: cellSplitting ( vector<Particle> &p ) {
	vector< vector<int> > neighbours;	
	return neighbours;
}


