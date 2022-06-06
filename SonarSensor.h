/**
*	@file   SonarSensor.h
*	@Author Çağla Çelik (152120131104)
*	@date   January 5,2021  
*   @brief  Header of SonarSensor class.
*
*	Provides data capture and management for sonar distance sensor.
 */

#ifndef SONARSENSOR
#define SONARSENSOR

#include "PioneerRobotAPI.h"

class SonarSensor {
	float ranges[16];
	PioneerRobotAPI *robotAPI;
public:
	SonarSensor(PioneerRobotAPI* robot) { robotAPI = robot; }
	~SonarSensor() { }

	/** Gets the distance information of the sensor with index i.
	* @return distance information of the sensor with index i.
	*/
	float getRange(int index);

	/** Gets the maximum value of the distance values.
	* @return the index of data with this distance to the variable in parentheses.
	*/
	float getMax(int &index);

	/** Gets the minimum value of the distance values.
	* @return the index of data with this distance to the variable in parentheses.
	*/
	float getMin(int &index);

	/** Uploads the robot's current sensor distance values ​​to the ranges array
	* @param ranges current sonar range readings (the range values are in millimeter)
	*/
	void updateSensor(float ranges[]);

	/** Sensor value with given the index
	* @return the sensor value with given the index
	*/
	float operator[](int i);

	/** Gets the angle value of the sensor
	* @return the angle value of the sensor with the given index .
	*/
	float getAngle(int index);

};














#endif
