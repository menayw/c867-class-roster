#include <iostream>
#include <string>
#include <iomanip>
#include "student.h"
#include "degree.h"
using std::cout;
using std::left;
using std::setw;

//constructor with default values
Student::Student()
{
	this->sID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = "";
	for (int i = 0; i < dayArraySize; i++) this->numDays[i] = 0;

}
//full constructor
Student::Student(string ID, string firstName, string lastName, string email, string age, double numDays[])
{
	this->sID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < dayArraySize; i++) this->numDays[i] = numDays[i];
}
//getters
string Student::getID() {
	return sID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmail() {
	return email;
}
string Student::getAge() {
	return age;
}
double* Student::getNumDays() {
	return numDays;
}
void Student::setID(string ID) {
	sID = ID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmail(string email) {
	this->email = email;
}
void Student::setAge(string age) {
	this->age = age;
}
void Student::setNumDays(double numDays[]) {
	for (int i = 0; i < dayArraySize; i++)
		this->numDays[i] = numDays[i];
}
//this print will print everything but the degree type
void Student::print() {
	cout << left << setw(5) << sID;
	cout << left << setw(10) << firstName;
	cout << left << setw(10) << lastName;
	cout << left << setw(25) << email;
	cout << left << setw(10) << age;
	cout << left << setw(5) << numDays[0];
	cout << left << setw(5) << numDays[1];
	cout << left << setw(10) << numDays[2];
}
Student::~Student() {
	//destructor
}
