/**
* @file Encryption.h
* @author Hande Birsen (152120181107)
* @date 07.01.2021
* @brief Header of Encryption class.
*
*	This file includes all the declarations of member variables and functions for Encryption class.
*/

#ifndef ENCRYPTION
#define ENCRYPTION
#include <iostream>
using namespace std;
//!  
/*!
* This class provides encryption and decryption of 4-digit numbers.
* 
*/
class Encryption
{
public:
	int encryptCode(int n)
	{
		
		int a = n / 1000;
		int b = (n % 1000) / 100;
		int c = (n % 100) / 10;
		int d = n % 10;
		
		a = (a + 7) % 10;
		b = (b + 7) % 10;
		c = (c + 7) % 10;
		d = (d + 7) % 10;
		cout << (c * 1000 + d * 100 + a * 10 + b) << endl;
		return (c * 1000 + d * 100 + a * 10 + b);  
	}

	int decryptCode(int n)
	{
		
		int a = n / 1000;
		int b = (n % 1000) / 100;
		int c = (n % 100) / 10;
		int d = n % 10;
	 
		a = (a + 3) % 10;
		b = (b + 3) % 10;
		c = (c + 3) % 10;
		d = (d + 3) % 10;
		cout << (c * 1000 + d * 100 + a * 10 + b) << endl;
		return (c * 1000 + d * 100 + a * 10 + b);
	}
};
#endif
