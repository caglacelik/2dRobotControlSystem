#pragma once
#include <iostream>

class Pose
{

private:
	float x;
	float y;
	float th;

public:
	Pose(float _x = 0, float _y = 0, float _th = 0 ) :x(_x), y(_y), th(_th) {}
	float getX();
	void setX(float);
	float getY();
	void setY(float);
	void setTh(float);
	float getTh();
	bool operator==(const Pose & x );
	Pose operator+(const Pose&) ;
	Pose operator-(const Pose&);
	Pose& operator+=(const Pose&) ;
	Pose& operator-=(const Pose&) ;
	bool operator<(const Pose&) ;
	void getPose(float& _x, float& _y, float& _th);
	void setPose(float _x, float _y, float _th);
	float findDistanceTo(Pose pos);
	float findAngleTo(Pose pos);



};



