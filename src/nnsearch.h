#include<vector>
#include<iostream>
#include<utility>
#include<string>
#include "particle.h"
#include "utility.h"

using namespace std;

#ifndef NNSEARCH_H
#define NNSEARCH_H

class NearestNeighbourSearch {
	/*

	Defines functions to computes the nearest neighbours for each particle in
	the particle system. The nearest neighbour search (nns) algorithm is the
	most crutial component of SPH simulation with regards to computational 
	speed. For that reason, many algorithms have been developed to compute it.

	*/
	
	vector<vector<int> > allPairsSearch( vector<Particle> &p );
	vector<vector<int> > cellIndexing( vector<Particle> &p );
	vector<vector<int> > spatialHashing( vector<Particle> &p );
	vector<vector<int> > cellSplitting( vector<Particle> &p );

public:
	NearestNeighbourSearch();
	vector<vector<int> > search(vector<Particle> &p, int);	
};

#endif 
