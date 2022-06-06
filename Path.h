/**
* @file Path.h
* @author Burak Kosova (152120171114)
* @date 02.01.2021
* @brief Header of Path class.
*
*	This file includes all the declarations of member variables and functions for Path class.
*/

#pragma once

#include "Node.h"

using namespace std;

//!  Path class is a linked list which contains nodes with position info.
/*!
 * Every node in the class holds position info inside a pose instance and a next pointer which points to the next node in the list.
 * List is empty when its created with only constructor.
*/

class Path
{
private:
	Node *head; //!< head member points to starting bound of the list (dummy root)
	Node *tail; //!< tail member points to last node in the list
	int length; //!< length member keeps track of the size

	/** Used to find the first node in the list. 
	* @return the first node's pointer 
	*/
	Node *begin();

	/** Used to find the ending bound of the list. 
	* @return the ending node pointer
	*/
	Node *end();

	/** Finds the node at the given index.
	* @param index is an integer argument which is node's index in the list (indices starts with zero)
	* @return the node pointer at the given index
	*/
	Node *findPos(int index);

	/** Finds the previous node.
	* @param pos is to determine which node's previous value is needed.
	* @return the previous node's pointer
	*/
	Node *findPrev(Node *pos);

public:
	/** Constructor creates an empty linked list.
	* Initializes the length value to 0.
	* Creates a node to be the beginning bound of the list. Head and tail points to this node.
	* Tail's next points to another node which is the ending bound of the list.
	*/
	Path();

	/** Destructor removes all of the nodes 
	* deletes all pointers and give them back to system (frees memory).
	*/
	~Path();

	/** Adds position to the end of the list.
	* @param pose is the position to be added.
	*/
	void addPos(Pose pose);

	/** Used to get position from the given index.
	* @param index is index of the node to be found. (starts from zero)
	*/
	Pose getPos(int index);

	/** Used to delete position from the given index.
	* @param index is index of the node to be deleted. (starts from zero)
	* @return true if removing is succesfull, otherwise false.
	*/
	bool removePos(int index);

	/** Used to insert position right after the given index.
	* @param index is an integer represents index of the node to be added after (starts from zero)
	* @param pose is the position to be added.
	* @return true if insert is succesfull, otherwise false.
	*/
	bool insertPos(int index, Pose pose);

	/** Used to print information about all of the positions in the list.
	*/
	void print();

	/** Overloads the [] opereator to get position at the given index.
	* @param index is an integer represents index of the position (starts from zero)
	* @return the position.
	*/
	Pose operator[](int index);

	/** Overloads the << operator to print information about all the positions in the list.
	*/
	friend ostream &operator<<(ostream &os, Path &path);

	/** Overloads the >> operator to get position info from the keyboard and adds it to the end of the list.
	*/
	friend istream &operator>>(istream &input, Path &path);
};
