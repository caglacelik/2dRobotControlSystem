#include "Pose.h"
#include <cmath>





float Pose::getX() {
	return x;
}
float Pose::getY() {
	return y;
}
float Pose::getTh() {
	return th;
}
void Pose::setX(float _x) {
	x = _x;
}
void Pose::setTh(float _th) {
	th = _th;
}
void Pose::setY(float _y) {
	y = _y;
}
bool Pose::operator==(const Pose& other) {
	if ((this->x) == (other.x) && (this->y) == (other.y) && (this->th) == (other.th))
		return true;
	else
		return false;
}
Pose Pose::operator+(const Pose& other) {
	Pose tmp;
	tmp.x = x + other.x;
	tmp.y = y  + other.y;
	tmp.th = th + other.th;
	return  tmp;
	
}Pose Pose::operator-(const Pose& other) {
	Pose tmp;
	tmp.x = x - other.x;
	tmp.y = y - other.y;
	tmp.th = th -  other.th;
	return tmp;

}
Pose& Pose::operator+=(const Pose& rhs) {
	this->x += rhs.x;
	this->y += rhs.y;
	this->th += rhs.th;
	
	return *this;
	

}
Pose& Pose::operator-=(const Pose& rhs) {
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->th += rhs.th;

	return *this;

}

bool Pose::operator <(const Pose& other) {
	if ((this->x) < (other.x) && (this->y) < (other.y) && (this->th) < (other.th) )
		return true;
	else
		return false;
}

void Pose::getPose(float& _x, float& _y, float& _th) {
	
	_x = x;
	_y = y;
	_th = th;
	
}
void Pose::setPose(float _x, float _y, float _th) {
	x = _x;
	y = _y;
	th = _th;	
}
float Pose::findDistanceTo(Pose pos) {
	float distance = sqrt(pow((this->x - pos.x), 2) + pow((this->y - pos.y), 2));
	return distance;
}
float Pose::findAngleTo(Pose pos) {
	float len1 = sqrt(pos.x * pos.x + pos.y * pos.y);
	float len2 = sqrt(this->x * this->x + this->y * this->y);

	float dot = pos.x * this->x + pos.y * this->y;

	float a = dot / (len1 * len2);

	if (a >= 1.0)
		return 0.0;
	else if (a <= -1.0)
		return 3.14;
	else
		return acos(a); // 0..PI
}




