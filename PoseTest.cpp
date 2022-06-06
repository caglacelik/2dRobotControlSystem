#include "pose.h"
#include <iostream>


int main() {

	Pose element;
	element.setX(120);
	element.setY(220);
	element.setTh(100);
	
	
	
	std::cout << element.getX() << element.getX() << element.getTh();


	return 0;
}