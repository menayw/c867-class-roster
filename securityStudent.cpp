#include <iostream>
#include "securityStudent.h"
using std::cout;

SecurityStudent::SecurityStudent() :Student()
{
	degType = SECURITY;
}


SecurityStudent::SecurityStudent(
	string	   sID,
	string	   firstName,
	string	   lastName,
	string	   email,
	string	   age,
	double	   numDays[],
	DegreeType degType
) : Student(sID, firstName, lastName, email, age, numDays)
{
	degType = SECURITY;
}

DegreeType SecurityStudent::getDegType()
{
	return SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << "\n";
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
}