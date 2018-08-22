#include "kernel.h"
#include "utility.h"
#include<cmath>
#include<vector>


using namespace std;

//Utility util;

float Kernel :: W(pair<float, float> &r1, pair<float, float> &r2, float h) {
 	Utility util;	
	float dist = util.calcEuclideanDistance(r1, r2);
	if (dist > h)
		return 0;
	else
		return pow(pow(h, 2) - pow(dist, 2), 3)*pow(h, -9);
	
}


pair<float, float> Kernel :: W_spiky_grad(pair<float, float> &r1, pair<float, float> &r2, float h) {
	Utility util;
	pair<float, float> r = make_pair(r1.first - r2.first, r1.second-r2.second);
		
	if (util.mod(r) > h)
		return make_pair(0.0, 0.0);
	else {
		float coeff = -45*pow((h-util.mod(r)), 2)/(3.14*pow(h, 6)*util.mod(r));
		float f_x = coeff * r.first;
		float f_y = coeff * r.second;
		return make_pair(f_x, f_y);
	} 
	
	

}

float Kernel :: W_visc_lapl(pair<float, float> &r1, pair<float, float> &r2, float h) {
	Utility util;
	pair<float, float> r = make_pair(r1.first - r2.first, r1.second - r2.second);

	if (util.mod(r) > h) 
		return 0;
	else
		return 45 * (h - util.mod(r))/(3.14*pow(h, 6));

}

