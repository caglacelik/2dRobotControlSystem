/**
* @file RobotOperator.h
* @author Hande Birsen (152120181107)
* @date 07.01.2021
* @brief Header of RobotOperator class.
*
*	This file includes all the declarations of member variables and functions for RobotOperator class.
*/
#ifndef ROBOTOPERATOR
#define ROBOTOPERATOR
#include "Encryption.h"
class RobotOperator 
{
	string name;//!< name member keeps operator's name
	string surname;//!< surname member keeps operator's surname
	unsigned int accessCode;//!< accessCode member keeps the encrypted code
	bool accessState; //!< accessState member checks checks whether it is true or false
	/** Encrypts 4 digit number by using Encryption class function
	* @param n is an integer argument to use in encryption
	* @return the encrypted code
	*/
	int encryptCode(int n); 
	/** Decryptes 4 digit number by using Encryption class function
	* @param n is an integer argument to use in decryption
	* @return the decrypted code
	*/
	int decryptCode(int n);
	
public:

	string getName() {
		return name;
	 }
	void setName(string name) {
		this->name=name;
	}
	string getSurname() {
		return surname;
	}
	void setSurname(string surname) {
		this->surname = surname;
	}
	/**RobotOperator constructor keeps accessCode,name and surname as default
	* Keeps accessState 'false' at first
	*/

	RobotOperator(unsigned int accessCode=1234, string name="hande", string surname="birsen") ;
	/** Used to check the entered code is the same as the code kept encrypted by accessCode  
	* @param int is index to be checked
	* @return true if the encrypted codes are the same, otherwise false.
	*/
	bool checkAccesCode(int);
	/** Used to print information about operator's name, surname and access status.
	*/
	void print() const;
};
#endif
