/**
*	@file   LaserSensor.h
*	@Author Çağla Çelik (152120131104)
*	@date   January 8,2021
*   @brief  Header of LaserSensor class.
*
*	Provides data capture and management for laser distance sensor.
 */


#ifndef LASERSENSOR
#define LASERSENSOR

#include "PioneerRobotAPI.h"

class LaserSensor {
	float ranges[181];
	PioneerRobotAPI* robotAPI;
public:
	LaserSensor(PioneerRobotAPI* robot) { robotAPI = robot; }
	~LaserSensor() { }

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
	float operator [](int i);

	/** Gets the angle value of the sensor
	* @return the angle value of the sensor with the given index .
	*/
	float getAngle(int index);

	/** The angle of the smallest distance on angle between startAngle and endAngle
	* @param startAngle is the lower bound angle 
	* @param endAngle is the upper bound angle 
	* @param angle is angle of the smallest distance
	* @return the smallest distance
	*/
	float getClosestRange(float startAngle, float endAngle, float &angle);
};

#endif
