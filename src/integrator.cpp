#include "integrator.h"
#include "utility.h"

using namespace std;


void Integrator :: leapFrog(Particle &p, float dt) {
	Utility util;
	pair<float, float> v = p.getVelocity();
        pair<float, float> f = p.getForce();
	float m = p.getMass();
	
	pair<float, float> dv = make_pair(f.first * dt/m, f.second * dt/m);
	v = util.add(v, dv);
	pair<float, float> r = p.getPosition();
	pair<float, float> dr = make_pair(dt * v.first, dt * v.second);
	cout << dr.second;
	r = util.add(r, dr);

	p.setVelocity(v);
	p.setPosition(r);

}
