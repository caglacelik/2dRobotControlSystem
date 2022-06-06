/**
* @file Node.h
* @author Burak Kosova (152120171114)
* @date 02.01.2021
* @brief Header of Node class.
*
*	This file includes all the declarations of member variables and functions for Node class.
*/

#pragma once

#include <iostream>
#include "Pose.h"

//! Node class is for creating the nodes in the Path linked list.

class Node
{
public:
	Pose pose;																	//!< Pose member is an instance of class Pose and holds position info
	Node *next;																	//!< Next member is a pointer to keep track of the next node in the list
	Node(Pose pos = Pose(), Node *next = NULL); //!< Node constructor creates a node with an empty position and null pointer next when called with no arguments
};
