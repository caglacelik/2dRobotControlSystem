/**
* @file RobotControl.cpp
* @author Þulenur Çörez (152120181038)
* @date 05.01.2021
* @brief Source file of RobotControl class.
*
*	This file includes all the declarations of the RobotControl class.
*/

#pragma once
//!  RobotControl is a class that controls all kinds of robot movements.
/*!
* Takes the robot and allows us to do operations on it.
* */
#include "PioneerRobotAPI.h"
#include "Pose.h"
#include <iostream>;
class RobotControl
{
private:
	int state; //!< This number represents the state of the robot.
	PioneerRobotAPI* robotAPI; //!<  The robot that takes in the constructor will be equal that robotAPI and the processes will continue with that robotAPI.
	Pose* position; //!< This class includes position and RobotControl class can make differences in that class.
public:
	/** Every class that contains robotAPI, must take same robot for the constructor. 
    * Creating a new robot when different classes are called is not what is desired.
	* @param robot is required for constructor to control same robot in the main from every class.
	*/
	RobotControl(PioneerRobotAPI* robot);

	/**
	* Deletes the robotAPI in the destructor.
	*/
	~RobotControl();

	/** Prints the positions of the robot.
	*/
	void print();

	/** This function turns the robot left from the functions in PionerRobotAPI.h file.
	* Uses turnRobot function and gives that function the direction left.
	*/
	void turnLeft();

	/** This function turns the robot right from the functions in PionerRobotAPI.h file.
	* Uses turnRobot function and gives that function the direction right.
	*/
	void turnRight();

	/** Allows the robot to move forward at the desired speed.
	* Uses moveRobot function and this function takes the speed.
	* @param speed is the speed of the robot that we want.
	*/
	void forward(float speed);

	/** Allows the robot to move backward at the desired speed.
	* Uses moveRobot function and this function takes the speed.
	* Speed will be given negative sign to the function.
	* @param speed is the speed of the robot that we want.
	*/
	void backward(float speed);

	/** Gets the pose class.
	* @return Pose object in the RobotControl.
	*/
	Pose getPose();

	/** Sets the pose class.
	* @param pos is the position that is desired of the robot.
	*/
	void setPose(Pose* pos);

	/** Allows the robot to stop its turn.
	* If robot is moving and turning, this function only stops turning of the robot.
	* Uses moveRobot function and gives it "0" for the parameter
	*/
	void stopTurn();

	/** Allows the robot to stop its move.
	* If robot is moving and turning, this function only stops moving backward or forward of the robot.
	* Uses turnRobot function and gives it forward direction for the parameter.
	*/
	void stopMove();
};