#include "Record.h"
#include "Pose.h"
#include <iostream>
using namespace std;
int main()
{
	string str;
	string str1;
	string read;
	string read2;

	Record r1;
	Record r2;
	if (r1.openFile())
	{
		str = "Test text";
		str1 = "Text test test test";

		read = r1.readLine();
		read2 = r1.readLine();
		cout << read << endl << read2 << endl;
		r1.writeLine(str);
		r1.writeLine(str1);
	}

	r1.closeFile();
	r1.setFileName("file5.txt");
	r1.openFile();
	Pose p(5, 10, 20);
	Pose p2;
	r1 << p;
	Record r3;
	r2 >> p;


}