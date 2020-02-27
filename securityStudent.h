#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class SecurityStudent : public Student
{
public:
	// constructors
	SecurityStudent();
	SecurityStudent(
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
	~SecurityStudent();

};
