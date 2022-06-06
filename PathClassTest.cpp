/**
* @file Path.h
* @author Burak Kosova (152120171114)
* @date 10.01.2021
* @brief Test of Path class.
*
*	This file is for testing purposes.
*/

#include "PioneerRobotAPI.h"
#include <iostream>
#include "Node.h"
#include "Pose.h"
#include "Path.h"

using namespace std;

//PioneerRobotAPI *robot;
//float sonars[16];
//float laserData[181];
//
//void print() {
//	cout << "MyPose is (" << robot->getX() << "," << robot->getY() << "," << robot->getTh() << ")" << endl;
//	cout << "Sonar ranges are [ ";
//	robot->getSonarRange(sonars);
//	for (int i = 0; i < 16; i++) {
//		cout << sonars[i] << " ";
//	}
//	cout << "]" << endl;
//	cout << "Laser ranges are [ ";
//	robot->getLaserRange(laserData);
//	for (int i = 0; i < 181; i++) {
//		cout << laserData[i] << " ";
//	}
//	cout << "]" << endl;
//}

int main() {

	/*robot=new PioneerRobotAPI;

	if (!robot->connect()) {
		cout << "Could not connect..." << endl;
		return 0;
	}

	robot->moveRobot(100);
	print();

	robot->turnRobot(PioneerRobotAPI::DIRECTION::left);
	Sleep(1000);
	print();

	robot->turnRobot(PioneerRobotAPI::DIRECTION::forward);
	Sleep(1000);
	print();

	robot->turnRobot(PioneerRobotAPI::DIRECTION::right);
	Sleep(1000);
	print();

	robot->stopRobot();
	robot->setPose(100, 200, 30);
	Sleep(1000);
	print();

	robot->setPose(1500, 2500, 3400);

	cout << "Press any key to exit...";
	getchar();

	robot->disconnect();
	delete robot;*/
	
	Pose pose(1, 2, 3);
	Pose pose1(5, 78, 35);
	Pose pose2(3, 4, 47);
	Pose pose3(35, 98, 33);
	Path p;
	
	try
	{
		p.addPos(pose);
		p.addPos(pose1);
		p.addPos(pose2);
		p.print();

		//this block throws index out of bound error
		/*cout << p.getPos(0).getX() << endl;
		cout << p.getPos(11).getX() << endl;
		cout << p[5].getTh() << endl;*/							 

		cout<<"Th value of position at index 1: " << p[1].getTh() << endl; // returns 35 which is the 'th' value of position at index 1

		p.removePos(0);
		cout << "remove at index -2: " << p.removePos(-2) << endl; // returns 0 because index -2 doesnt exist
		p.print();

		p.insertPos(1, pose3);
		cout<< "insert at index 3: " << p.insertPos(3, pose3) << endl; // returns 0 because index 3 doesnt exist
		p.print();



		cout << p;		// outputs the positions in the path (same as print method)
		cin >> p;		// gets position values from console and adds it to the path
		cout << p;

	}
	catch (const char* e)
	{
		cout << e << endl;
	}

	return 0;
}