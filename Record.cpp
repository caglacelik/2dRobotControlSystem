/**
* @file Record.cpp
* @author Þulenur Çörez (152120181038)
* @date 08.01.2021
* @brief Source file of Record class.
*
*	This file includes all the implementations of member variables and functions for Record class.
*/

#include "Record.h"

//!  It is a class that controls writing and reading from/to the file.
/*!
* It contains almost all functions for file stream.
* Allows us to do operations such as writing, reading, and opening files.
*/

bool Record::openFile()
{
	file.open(filename, ios::out | ios::app | ios::in);
	if (file.is_open())
	{
		return true;
	}
	cout << "Error opening '" << filename << "' !" << endl;
	return false;
}

void Record::closeFile()
{
	file.close();
}

void Record::setFileName(string name)
{
	filename = name;
}

string Record::readLine()
{
	string tp="";
	if (file.is_open())
	{
		getline(file, tp);
		cout << "'" << tp << "' string is read from " << "'" << filename << "'" << endl;
		return tp;
	}
	cout << "Error. '" << filename << "' is not opened!" << endl;
	return tp;
}

bool Record::writeLine(string str)
{
	if (file.is_open())
	{
		file << str << endl;
		cout << "Writing line is completed: '"<<str<<"' string is writed into "<<filename << endl;
		return true;
	}
	
	cout << "Error. '" << filename << "' is not opened!" << endl;
	return false;
}


Record& Record::operator<<(Pose& pose)
{
	file << pose.getX() << endl;
	file << pose.getY() << endl;
	file << pose.getTh() << endl;
	return *this;
}

Record& Record::operator>>(Pose& pose)
{
	return *this;
}
