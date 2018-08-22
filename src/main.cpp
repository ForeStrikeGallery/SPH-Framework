#include "simulator.h"

using namespace std;


int main() {
	Simulator simulator;
	int steps = 0;
	string filename = "test4.txt";
	while(steps++ < 10) {
		cout << "Step: " << steps << endl;
		simulator.runSPH();
		simulator.saveDataToFile(filename);
		
	}
	return 0;
}
