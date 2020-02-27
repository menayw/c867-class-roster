#include <iostream>
#include "softwareStudent.h"
using std::cout;

SoftwareStudent::SoftwareStudent() :Student()
{
	degType = SOFTWARE;
}


SoftwareStudent::SoftwareStudent(
	string	   sID,
	string	   firstName,
	string	   lastName,
	string	   email,
	string	   age,
	double	   numDays[],
	DegreeType degType
) : Student(sID, firstName, lastName, email, age, numDays)
{
	degType = SOFTWARE;
}

DegreeType SoftwareStudent::getDegType()
{
	return SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}