#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class SoftwareStudent : public Student
{
public:
	// constructors
	SoftwareStudent();
	SoftwareStudent(
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
	~SoftwareStudent();

};
