/**
* @file Menu.cpp
* @date 05.01.2021
* @brief Menu of the robot.
*
*	Menu of the robot that contains all functions and controls of the robot.
*/


//!  Robot menu.
/*!
* Robot can be controlled by user in this menu easily. There is a good design.
* */
#include "PioneerRobotAPI.h"
#include "RobotControl.h"
#include <iostream>
#include "SonarSensor.h"
#include "LaserSensor.h"
using namespace std;

PioneerRobotAPI* robot;

/**Prints main menu
*/
void printMainMenu();

/**Prints connection menu
*/
void printConnectionMenu();

/**Prints motion menu
*/
void printMotionMenu();

/**Prints sensor menu
*/
void printSensorMenu();

/**Prints sonar sensor menu
*/
void printSonarSensor();

/**Prints laser sensor menu
*/
void printLaserSensor();

int main()
{
	robot = new PioneerRobotAPI;
	RobotControl robotControl(robot);
	SonarSensor sonarsensor(robot);
	LaserSensor lasersensor(robot);
	int choose;
	int choose2;
	int choose3;
	for (int i = 0;;)
	{
		if (i == 0)
		{
			printMainMenu();
			cin >> choose;
			if (choose == 1)
			{
				i++;
			}
			if (choose == 2)
			{
				i++;
			}
			if (choose == 3)
			{
				i++;
			}
			if (choose == 4)
			{
				system("pause");
				return 0;
			}
		}
		if (i == 1 && choose == 1)
		{
			printConnectionMenu();
			cin >> choose2;
			if (choose2 == 1)
			{
				if (!robot->connect()) {
					cout << "Could not connect..." << endl;
					return 0;
				}
				cout << "<connect>" << endl;
				cout << "Robot connected. " << endl << endl;
				//connect robot
			}
			if (choose2 == 2)
			{
				robot->disconnect();
				cout << "<disconnect>" << endl;
				cout << "Robot disconnected. " << endl << endl;
				//disconnect
			}
			if (choose2 == 3)
			{
				//back
				i -= 1;
			}
		}
		if (i == 1 && choose == 2)
		{
			printMotionMenu();
			cin >> choose2;
			if (choose2 == 1)
			{
				cout << "Enter speed (mm/s)" << endl;
				float speed;
				cin >> speed;
				robot->moveRobot(speed);
			}
			if (choose2 == 2)
			{

			}
			if (choose2 == 3)
			{
				robotControl.turnLeft();
			}
			if (choose2 == 4)
			{
				robotControl.turnRight();
			}
			if (choose2 == 5)
			{
				cout << "Enter speed (mm/s)" << endl;
				float speed;
				cin >> speed;
				robotControl.forward(speed);
			}
			if (choose2 == 6)
			{
			}
			if (choose2 == 7)
			{
			}
			if (choose2 == 8)
			{
				//back
				i -= 1;
			}
		}

		if (i == 1 && choose == 3)
		{
			// Sensor
			printSensorMenu();
			cin >> choose2;
			if (choose2 == 1)
			{
				printSonarSensor();
				cin >> choose3;
				if (choose3 == 1)
				{
					cout << "Enter index between 0 and 15" << endl;
					int c;
					cin >> c;
					cout << "Sonar index " << c << " range : " << sonarsensor.getRange(c) << endl;
				}
				if (choose3 == 2)
				{
					int index = 0;
					sonarsensor.getMin(index);
					cout << "Minimum sonar range index: "<< index <<"   Min sonar range : "<<sonarsensor.getMin(index) << endl;
					//
				}
				if (choose3 == 3)
				{
					int index = 0;
					sonarsensor.getMax(index);
					cout << "Maximum sonar range index: " << index << "   Max sonar range : " << sonarsensor.getMax(index) << endl;
				}
				if (choose3 == 4)
				{
					i -= 1;
				}

			}
			if (choose2 == 2)
			{
				printLaserSensor();
				cin >> choose3;
				if (choose3 == 1)
				{
					cout << "Enter index between 0 and 180" << endl;
					int c;
					cin >> c;
					cout << "Laser index " << c << " range : " << lasersensor.getRange(c) << endl;
					//
				}
				if (choose3 == 2)
				{
					int index = 0;
					lasersensor.getMin(index);
					cout << "Minimum laser range index: " << index << "   Min laser range : " << lasersensor.getMin(index) << endl;
					//
				}
				if (choose3 == 3)
				{
					int index = 0;
					lasersensor.getMin(index);
					cout << "Maximum laser range index: " << index << "   Max laser range : " << lasersensor.getMin(index) << endl;
					//
				}
				if (choose3 == 4)
				{
					i -= 1;
				}

			}
			if (choose2 == 3)
			{
				i -= 1;
			}

		}
	}


}

void printMainMenu()
{
	cout << "Main Menu" << endl;
	cout << "1. Connection" << endl;
	cout << "2. Motion" << endl;
	cout << "3. Sensor" << endl;
	cout << "4. Quit" << endl;
	cout << "Choose one : " << endl;
}

void printConnectionMenu()
{
	cout << "Connection Menu" << endl;
	cout << "1. Connect Robot" << endl;
	cout << "2. Disconnect Robot" << endl;
	cout << "3. Back" << endl;
}

void printMotionMenu()
{
	cout << "Motion Menu" << endl;
	cout << "1. Move robot" << endl;
	cout << "2. Safe Move robot" << endl;
	cout << "3. Turn left" << endl;
	cout << "4. Turn right" << endl;
	cout << "5. Forward" << endl;
	cout << "6. Move distance" << endl;
	cout << "7. Close wall" << endl;
	cout << "8. Back" << endl;
	cout << "Choose one : " << endl;
}

void printSensorMenu()
{
	cout << "Sensor Menu" << endl;
	cout << "1. Sonar sensor" << endl;
	cout << "2. Laser sensor" << endl;
	cout << "3. Back" << endl;

}

void printSonarSensor()
{
	cout << "Sonar Sensor Menu" << endl;
	cout << "1. Range" << endl;
	cout << "2. Minimum" << endl;
	cout << "3. Maximum" << endl;
	cout << "4. Back" << endl;
}

void printLaserSensor()
{
	cout << "Laser Sensor Menu" << endl;
	cout << "1. Range" << endl;
	cout << "2. Minimum" << endl;
	cout << "3. Maximum" << endl;
	cout << "3. Back" << endl;
}