/**
* @file RobotControl.cpp
* @author Þulenur Çörez (152120181038)
* @date 05.01.2021
* @brief Source file of RobotControl class.
*
*	This file includes all the implementations declared in the RobotControl header file.
*/



#include "RobotControl.h"

RobotControl::RobotControl(PioneerRobotAPI* robot): state(1)
{
	robotAPI = robot;
}

RobotControl::~RobotControl()
{
	delete robotAPI;
}

void RobotControl::turnLeft()
{
	robotAPI->turnRobot(PioneerRobotAPI::DIRECTION::left);
}

void RobotControl::turnRight()
{
	robotAPI->turnRobot(PioneerRobotAPI::DIRECTION::right);
}

void RobotControl::forward(float speed)
{
	robotAPI->moveRobot(speed);
}

void RobotControl::backward(float speed)
{
	robotAPI->moveRobot(-speed);
}

void RobotControl::stopMove()
{
	robotAPI->moveRobot(0);
}

void RobotControl::stopTurn()
{
	robotAPI->turnRobot(PioneerRobotAPI::DIRECTION::forward);
}

Pose RobotControl::getPose()
{
	return *position;
}

void RobotControl::setPose(Pose* pos)
{
	robotAPI->setPose(pos->getX(), pos->getY(), pos->getTh());
}

void RobotControl::print()
{
	std::cout << "Positions :" << robotAPI->getX() << "  " << robotAPI->getY() << "  " << robotAPI->getTh() << std::endl;
}


