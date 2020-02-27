#include <iostream>
#include "networkStudent.h"
using std::cout;

NetworkStudent::NetworkStudent() :Student()
{
	degType = NETWORK;
}


NetworkStudent::NetworkStudent(
	string	   sID,
	string	   firstName,
	string	   lastName,
	string	   email,
	string	   age,
	double	   numDays[],
	DegreeType degType
) : Student(sID, firstName, lastName, email, age, numDays)
{
	degType = NETWORK;
}

DegreeType NetworkStudent::getDegType()
{
	return NETWORK;
}

void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << "\n";
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
}