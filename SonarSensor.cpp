/**
*	@file   SonarSensor.h
*	@Author Çaðla Çelik (152120131104)
*	@date   January 6,2021
*   @brief  Source file of SonarSensor class.
*
*   Ýmplementations of the functions in SonarSensor header file.
 */

#include "SonarSensor.h"
#include <iostream>

using namespace std;

float SonarSensor::getRange(int index) {
    robotAPI->getSonarRange(ranges);
    return ranges[index];
}

float SonarSensor::getAngle(int index){
	
	int sayac = 90;
	for (int a = 0; a < 16; a++)
	{
		if (index == a)
		{
			if (a > 7)
			{
				return abs(360 + sayac - robotAPI->getTh());
			}
			else
			{
				return (robotAPI->getTh() + sayac);
			}
		}
		sayac = sayac - 20;
		if (a == 0) sayac = sayac - 20;
		if (a == 6) sayac = sayac - 20;
		if (a == 7) sayac += 20;
		if (a == 8) sayac = sayac - 20;
		if (a == 13) sayac += 20;
		if (a == 14) sayac = sayac - 20;
	}

}

float SonarSensor::getMax(int &index) {

	float max = ranges[0];
	for (int i = 0; i < 16; i++) {
		if (ranges[i] > max)
		{
			max = ranges[i];
			index = i;
		}
	}
		return max;
	
}

float SonarSensor::getMin(int& index) {

	float min=ranges[0];
	for (int i = 0; i < 16; i++) {
		if (ranges[i] < min)
		{
			min = ranges[i];
			index = i;
		}
	}
		return min;
	
}

void SonarSensor::updateSensor(float ranges[]) {
    robotAPI->getSonarRange(ranges);
}

float SonarSensor::operator[](int i) {
	if (i > 16) {
		cout << "Index out of bounds!" << endl;
	}
	return ranges[i];
}



