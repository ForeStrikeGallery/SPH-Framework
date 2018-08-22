#ifndef KERNEL_H
#define KERNEL_H

#include<utility>
using namespace std;

class Kernel {

public:
	float W(pair<float, float> &r1, pair<float, float> &r2, float h);
	pair<float, float>  W_spiky_grad(pair<float, float> &r1, pair<float, float> &r2, float h);
        float W_visc_lapl(pair<float, float> &r1, pair<float, float> &r2, float h);
       // float W_poly6_grad(pair<float, float> &r1, pair<float, float> &r2, float h); 

};

#endif
