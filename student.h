#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student {

public:
	const static int dayArraySize = 3;//if value ever changes I only have to change it here

protected:
	string	   sID;
	string	   firstName;
	string	   lastName;
	string	   email;
	string	   age;
	double	   numDays[dayArraySize];//3 course days so an array of size 3
	DegreeType degType;

public:
	Student();// constructor

	//full constructor without degree type, subclasses will do that
	Student(string ID, string firstName, string lastName, string email, string age, double numDays[]);

	//getters
	string     getID();
	string     getFirstName();
	string     getLastName();
	string     getEmail();
	string     getAge();
	double* getNumDays();
	virtual DegreeType getDegType() = 0;//leaves it to subclass to do

	//setters
	void setID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(string age);
	void setNumDays(double numDays[]);

	virtual void print() = 0;

	//destructor
	~Student();

};

