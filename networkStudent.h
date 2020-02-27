#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class NetworkStudent : public Student
{
public:
	// constructors
	NetworkStudent();
	NetworkStudent(
		string	   sID,
		string	   firstName,
		string	   lastName,
		string	   email,
		string	   age,
		double	   numDays[],
		DegreeType degType
	);

	DegreeType getDegType();
	void print();

	// deconstructor
	~NetworkStudent();

};