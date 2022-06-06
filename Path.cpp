/**
* @file Path.cpp
* @author Burak Kosova (152120171114)
* @date 02.01.2021
* @brief Source file of Path class.
*
*	This file includes all the implementations declared in the Path header file.
*/

#include "Path.h"

Path::Path()
{
	length = 0;
	head = new Node();
	tail = head;
	tail->next = new Node();
}

Path::~Path()
{
	for (int i = 0; i < length; i++)
	{
		removePos(i);
	}
	delete tail->next;
	delete tail;
}

Node *Path::begin() { return head->next; }
Node *Path::end() { return tail->next; }

Node *Path::findPos(int index)
{
	if (begin() == end())
		throw "Error: List is empty!";

	if (index < 0 || index > length - 1)
		throw "Error: Index out of bound!";

	Node *temp = begin();
	for (int i = 0; i < index; i++)
		temp = temp->next;
	return temp;
}

Node *Path::findPrev(Node *p)
{
	Node *temp = head;
	Node *stop = end();
	while (temp != stop && temp->next != p)
		temp = temp->next;
	return temp;
}

void Path::addPos(Pose pose)
{
	tail->next = new Node(pose, tail->next);
	tail = tail->next;
	length++;
}

Pose Path::getPos(int index) { return findPos(index)->pose; }

bool Path::removePos(int index)
{
	if (begin() == end() || index < 0 || index > length - 1)
		return false;
	else
	{
		Node *pos = findPos(index);
		Node *prev = findPrev(pos);
		prev->next = pos->next;
		if (pos == tail)
		{
			tail = prev;
		}
		delete pos;
		length--;
		return true;
	}
}

bool Path::insertPos(int index, Pose pose)
{
	if (index == 0 && length == 0)
	{
		addPos(pose);
		return true;
	}

	if (index < 0 || index > length - 1)
		return false;

	if (index == length - 1)
	{
		addPos(pose);
		return true;
	}
	else
	{
		Node *temp = findPos(index);
		temp->next = new Node(pose, temp->next);
		length++;
		return true;
	}
}

Pose Path::operator[](int index) { return findPos(index)->pose; }

void Path::print()
{
	cout << "Current positions in the path: ";
	Node *temp = begin();
	while (temp != end())
	{
		cout << "(" << temp->pose.getX() << "," << temp->pose.getY() << "," << temp->pose.getTh() << ")"
				 << " ";
		temp = temp->next;
	}
	cout << endl;
}

ostream &operator<<(ostream &os, Path &path)
{
	os << "Current positions in the path: ";
	Node *temp = path.begin();
	while (temp != path.end())
	{
		os << "(" << temp->pose.getX() << "," << temp->pose.getY() << "," << temp->pose.getTh() << ")"
			 << " ";
		temp = temp->next;
	}
	os << endl;
	return os;
}

istream &operator>>(istream &input, Path &path)
{
	float x, y, th;
	input >> x >> y >> th;
	path.addPos(Pose(x, y, th));
	return input;
}
