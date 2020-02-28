#include "roster.h"
#include "degree.h"
#include "student.h"
using std::cout;
using std::cerr;

Roster::Roster() {
    this->capacity = 0;
    this->lastIndex = -1;
    this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
    this->capacity = capacity;
    this->lastIndex = -1;
    this->classRosterArray = new Student * [capacity];
}

/*Student* Roster::getStudentAt(int index)
{
    return classRosterArray[index];
}*/

void Roster::parseThenAdd(string row)
{
    if (lastIndex < capacity) {
        lastIndex++;
        DegreeType d;
        //test which degree type it is.
        if (row.back() == 'Y') d = SECURITY;
        else if (row.back() == 'E') d = SOFTWARE;
        else if (row.back() == 'K') d = NETWORK;
        else {
            cerr << "ERROR! Invalid Degree Type. Exiting now \n";
            exit(-1);
        }
        //find the commas
        int rhs = row.find(",");

        //find ID
        string stID = row.substr(0, rhs);

        //find first name
        int lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string sFirstName = row.substr(lhs, rhs - lhs);

        //find last name
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string sLastName = row.substr(lhs, rhs - lhs);

        //find email
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string sEmail = row.substr(lhs, rhs - lhs);

        //find age
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string sAge = row.substr(lhs, rhs - lhs);


        //findmake each temp day variable
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        double sDay1 = stod(row.substr(lhs, rhs - lhs));
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        double sDay2 = stod(row.substr(lhs, rhs - lhs));
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        double sDay3 = stod(row.substr(lhs, rhs - lhs));

        //put all temp variables back together
        add(stID, sFirstName, sLastName, sEmail, sAge, sDay1, sDay2, sDay3, d);
    }
    else {
        cerr << "There has been a processing error.\n Exiting Now";
        exit(-1);
    }
}

void Roster::add(string stID, string sFirstName, string sLastName, string sEmail, string sAge, double sDay1, double sDay2, double sDay3, DegreeType deg)
{
    //create day array and add degree type
    double numDays[Student::dayArraySize];
    numDays[0] = sDay1;
    numDays[1] = sDay2;
    numDays[2] = sDay3;
    if (deg == SECURITY) classRosterArray[lastIndex] = new SecurityStudent(stID, sFirstName, sLastName, sEmail, sAge, numDays, deg);
    else if (deg == NETWORK) classRosterArray[lastIndex] = new NetworkStudent(stID, sFirstName, sLastName, sEmail, sAge, numDays, deg);
    else classRosterArray[lastIndex] = new SoftwareStudent(stID, sFirstName, sLastName, sEmail, sAge, numDays, deg);
}

void Roster::remove(string sID)//bool
{
    /*  bool found = false;
      for (int i = 0; i <= lastIndex; i++) {
          if (this->classRosterArray[i]->getID() == sID)//if the student is found
          {
              found = true;
              //delete it
              delete this->classRosterArray[i];
              this->classRosterArray[i] = this->classRosterArray[lastIndex];
              lastIndex--;
          }
      }
      return found;//if student is not found, found stays false*/
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] == nullptr) {
            cout << "ERROR! Student ID: " << sID << " not found.\n";
            break;
        }
        else if (sID == classRosterArray[i]->getID()) {
            classRosterArray[i] = nullptr;
            cout << "Student removed\n";
        }
    }
    cout << "\n----------------------------------------------- \n";
}

void Roster::print_All()
{
    cout << "Displaying all Students:\n\n";

    for (int i = 0; i <= this->lastIndex; i++)(this->classRosterArray)[i]->print();
}

void Roster::printAvgNumDays(string sID)
{

    bool found = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getID() == sID)//if the student is found
        {
            found = true;
            double* d = classRosterArray[i]->getNumDays();
            cout << "Average number of days in a course for student " << sID << " is " << (d[0] + d[1] + d[2]) / 3 << "\n";
        }
    }
    if (!found) cout << "Student not found; \n";

}

void Roster::printInvalidEmail()
{
    cout << "\n-----------------------------------------------\n";
    cout << "Displaying invalid email entries:\n\n";
    for (int i = 0; i <= lastIndex; ++i) {
        string email = classRosterArray[i]->getEmail();
        if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos)) {
            cout << "The email for Student " << classRosterArray[i]->getID() << " is not valid: " << email << "\n";
        }
    }
    cout << "\n----------------------------------------------- \n";
}

void Roster::printByDegType(DegreeType d)
{
    cout << "\n----------------------------------------------- \n";
    cout << "Printing Students by Degree Type: " << degreeTypeStrings[d] << "\n\n";
    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getDegType() == d)this->classRosterArray[i]->print();
    }
    cout << "\n----------------------------------------------- \n";
}

Roster::~Roster()//delete all students 
{
    for (int i = 0; i <= lastIndex; i++)
    {
        delete this->classRosterArray[i];
    }
    delete this;
}

int main()
{
    //Add a title to the output
    cout << "----------------------------------------------- \n";
    cout << "Scripting and Programming - Applications - C867 \n";
    cout << "C++ \n";
    cout << "ID001243438 \n";
    cout << "Menay Wilde \n";
    cout << "\n----------------------------------------------- \n";


    //parse the data
    Roster* classRoster = new Roster(numStudents);
    for (int i = 0; i < numStudents; i++) {//add students to roster
        classRoster->parseThenAdd(studentData[i]);
    }

    //display all students
    classRoster->print_All();

    //print any emails that have an error
    classRoster->printInvalidEmail();


    //print avg # of days in 3 courses for each student
    cout << "Printing Average Number of Days in a Course Per Student:\n\n";
    for (int i = 0; i < numStudents; i++) {
        classRoster->printAvgNumDays(classRoster->classRosterArray[i]->getID());
    }


    //print student by their degree type if they are a software student
    classRoster->printByDegType((DegreeType)SOFTWARE);

    //remove with student id A3
    cout << "Removing Student A3:\n\n";
    classRoster->remove("A3");

    //remove again to check and send out the error code to verify
    cout << "Removing Student A3:(to check it was properly removed)\n\n";
    classRoster->remove("A3");

    system("pause");//hold window open
    return 0;
}

