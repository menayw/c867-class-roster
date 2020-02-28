#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"

const int numStudents = 5;
string studentData[numStudents] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Menay,Wilde,mwild33@wgu.edu,27,10,15,20,SOFTWARE"
};

class Roster {
private:
	int lastIndex;
	int capacity;


public:
	Roster();
	Roster(int capacity);
	Student** classRosterArray;
	//	Student* getStudentAt(int index);
	void parseThenAdd(string datarow);
	void add(string stID, string sFirstName, string sLastName, string sEmail, string sAge, double sDay1, double sDay2, double sDay3, DegreeType deg);
	void print_All();
	void remove(string sID);
	void printAvgNumDays(string sID);
	void printInvalidEmail();
	void printByDegType(DegreeType d);
	~Roster();
};
