#include "integrator.h"
#include "utility.h"

using namespace std;


void Integrator :: leapFrog(Particle &p, float dt, Boundary B) {
	if (p.getType() == 1) 
		return;

	Utility util;
	pair<float, float> v = p.getVelocity();
        pair<float, float> f = p.getForce();
	float m = p.getMass();
	//cout << "V " << v.second;

	//cout << "Force y: " << f.second << " Force x: " << f.first << endl;;
		
	pair<float, float> dv = make_pair(f.first * dt/m, f.second * dt/m);
	v = util.add(v, dv);
	pair<float, float> r = p.getPosition();
	pair<float, float> dr = make_pair(dt * v.first, dt * v.second);
///	cout << "before2 " << r.second;
	r = util.add(r, dr);

///	cout << "after2 " << r.second << endl;
	 
	p.setVelocity(v);
	if (r.first < B.xmin)
		r.first = B.xmin;
	if (r.first > B.xmax)
		r.first = B.xmax;

	if (r.second < B.ymin)
		r.second = B.ymin;
	if (r.second > B.ymax) 
		r.second = B.ymax;

	p.setPosition(r);

}
