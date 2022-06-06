/**
* @file Record.h
* @author Þulenur Çörez (152120181038)
* @date 08.01.2021
* @brief Header of Record class.
*
*	This file includes all the declarations of member variables and functions for Record class.
*/

#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "Pose.h"
using namespace std;
class Record
{
private:
	string filename; //!< filename member.  
	fstream file; //!< file member.
	Pose* position; //!< position member. It keeps the position.
public:

	/** Constructor for Record class
	* If file does not take string while creating, filename will be "file.txt". 
	* @param fileName while creating the class, it allows us set the name.
	*/
	Record(string fileName = "file.txt") :filename(fileName) {}

	/** Opens the file that named "filename".
	* @return false if an error happens.
	* @return true if file is opened.
	*/
	bool openFile();

	/** Closes the file that named "filename".
	*/
	void closeFile();

	/** Sets the name of the file as desired.
	* the private member filename of Record class will change with that filename.
	* @param name is the filename that is desired to change.
	*/
	void setFileName(string name);

	/** Reads one line from the file and returns it.
	* @return the one line string that read.
	*/
	string readLine();

	/** Writes the string to the file.
	* @return false if an error happens.
	* @return true if file is opened and string is wrote.
	*/
	bool writeLine(string);

	/** Overload << operator to write the pose object's properties to the file.
	* @return the record class.
	*/
	Record& operator<<(Pose&);

	/** Overload >> operator to read the pose object's properties from the file.
	* @return the record class.
	*/
	Record& operator>>(Pose&);
};


