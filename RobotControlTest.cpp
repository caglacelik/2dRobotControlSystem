#include "PioneerRobotAPI.h"
#include "RobotControl.h"
#include <iostream>
using namespace std;

PioneerRobotAPI* robot;



int main() {

	robot = new PioneerRobotAPI;
	if (!robot->connect()) {
		cout << "Could not connect..." << endl;
		return 0;
	}

	RobotControl robotcontrol(robot);
	float x = 1;
	float y = 1;
	float th = 1;
	robotcontrol.setPose(new Pose);

	robotcontrol.print();
	robotcontrol.forward(1000);
	Sleep(1000);
	
	robotcontrol.print();
	robotcontrol.turnLeft();
	Sleep(1500);

	robotcontrol.print();
	robotcontrol.stopTurn();
	Sleep(1500);

	robotcontrol.print();
	robotcontrol.backward(1000);
	Sleep(500);

	robotcontrol.print();
	robotcontrol.stopMove();
	Sleep(1500);

	robotcontrol.print();
	robotcontrol.turnRight();
	Sleep(1500);

	robotcontrol.print();
	robotcontrol.stopTurn();
	Sleep(1500);

	robotcontrol.print();
	robotcontrol.forward(10000);
	Sleep(5000);

	robotcontrol.print();
	robotcontrol.stopMove();
	Sleep(1500);

	robotcontrol.print();
	cout << "Press any key to exit...";
	getchar();

	robot->disconnect();
	delete robot;
	return 0;

}