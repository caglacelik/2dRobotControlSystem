/**
*	@file   LaserSensor.cpp
*	@Author Çaðla Çelik (152120131104)
*	@date   January 7,2021
*   @brief  Source file of LaserSensor class.
*
*   Ýmplementations of the functions in LaserSensor header file.
 */

#include "LaserSensor.h"
#include <iostream>

using namespace std;

float LaserSensor::getRange(int index){

	robotAPI->getLaserRange(ranges);
	return ranges[index];
}

float LaserSensor::getAngle(int index) {

	for (int i = 0; i < 181; i++)
	{
		if (index == i) {
			return index;
		}
	}
}

	float LaserSensor::getMax(int& index) {

		float max = ranges[0];
		for (int i = 0; i < 181; i++){ 
			if (ranges[i] > max)
			{
				max = ranges[i];
				index = i;
			}	
		}
		return max;
	}

	float LaserSensor::getMin(int& index){

	float min = ranges[0];
	for (int i = 0; i < 181; i++) {
		if (ranges[i] < min)
		{
			min = ranges[i];
			index = i;
		}
	}
		return min;
}

void LaserSensor::updateSensor(float ranges[]) {

	return robotAPI->getSonarRange(ranges);
}

float LaserSensor::operator [](int i) {

	if (i > 181) {
		cout << "Index out of bounds!" << endl;
	}
	return ranges[i];
}

float LaserSensor::getClosestRange(float startAngle, float endAngle, float& angle) {
	int i;
	for (i = startAngle; i < endAngle; i++) {
		if (ranges[i] < angle )
		{
			angle = i;
		}
	}
			return ranges[i];

}