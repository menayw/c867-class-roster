#pragma once
#include <string>
#include <iostream>
#include "degree.h"
#include "student.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"


class Roster {
private:
	int lastIndex;
	int capacity;
	Student** classRosterArray;

public:
	Roster();
	Roster(int capacity);

	Student* getStudentAt(int index);
	void parseThenAdd(string datarow);
	void add(string stID, string sFirstName, string sLastName, string sEmail, string sAge, double sDay1, double sDay2, double sDay3, DegreeType deg);
	void print_All();
	bool remove(string sID);
	void printAvgNumDays(string sID);
	void printInvalidEmail();
	void printByDegType(DegreeType d);
	~Roster();
};
