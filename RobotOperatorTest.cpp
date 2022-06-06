#include <iostream>
#include "RobotOperator.h"
#include "Encryption.h"
using namespace std;

int main()
{
	RobotOperator op;

	op.print();
	cout << op.checkAccesCode(1234) << endl;
	op.print();
	return 0;
}