
#include "SonarSensor.h"
#include "LaserSensor.h"

using namespace std;

PioneerRobotAPI* robot;

int main() {
	robot = new PioneerRobotAPI;
	 robot->connect();
	SonarSensor ss(robot);
	cout << ss.getAngle(5) << endl;
	cout << ss.getRange(8) << endl;
	int maxIndex = 0;
	int minIndex = 0;
	cout << ss.getMax(maxIndex) << endl;
	cout << maxIndex << endl;
	cout << ss.getMin(minIndex) << endl;
	cout << minIndex << endl;
	cout << ss[8] << endl;

	LaserSensor ls(robot);

	cout << ls.getAngle(4) << endl;
	cout << ls.getRange(8) << endl;
	int maxIndex = 0;
	int minIndex = 0;
	cout << ls.getMax(maxIndex) << endl;
	cout << maxIndex << endl;
	cout << ls.getMin(minIndex) << endl;
	cout << minIndex << endl;
	cout << ls[7] << endl;

	delete robot;
}


