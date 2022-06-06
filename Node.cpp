/**
* @file Node.cpp
* @author Burak Kosova (152120171114)
* @date 02.01.2021
* @brief Source file of Node class.
*
*	This file includes all the implementations declared in the Node header file.
*/

#include "Node.h"

Node::Node(Pose pos, Node *next) : pose(pos), next(next) {}
