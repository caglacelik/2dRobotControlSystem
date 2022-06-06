/**
* @file RobotOperator.cpp
* @author Hande Birsen (152120181107)
* @date 07.01.2021
* @brief Source of RobotOperator class.
*
*	This file includes all the implementations declared in the RobotOperator and Encryption header file.
*/
#include <iostream>
#include "RobotOperator.h"
#include "Encryption.h"
using namespace std;
Encryption e;
RobotOperator::RobotOperator(unsigned int accessCode, string name, string surname) : name(name), surname(surname),accessState(false)
{
	this->accessCode = encryptCode(accessCode);
}
int RobotOperator::encryptCode(int code) {
	return e.encryptCode(code);
	
}
int RobotOperator::decryptCode(int code) {
	return e.decryptCode(code);
}
bool RobotOperator::checkAccesCode(int n) {
	if (accessState = n == decryptCode(accessCode)) {
		cout << "You have entered the code correctly. " << endl;
		return accessState;
	}
	else {
		cout << "Ooops try again." << endl;
		return accessState;
	}
}
void RobotOperator::print()const {
	cout << name << " " << surname << " " << accessState << " " << endl;
}