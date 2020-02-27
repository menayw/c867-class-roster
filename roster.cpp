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

Student* Roster::getStudentAt(int index)
{
    return classRosterArray[index];
}

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

bool Roster::remove(string sID)
{
    bool found = false;
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
    return found;//if student is not found, found stays false
}

void Roster::print_All()
{
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
    cout << "\n-----------------------------------------------\n \n";
    cout << "Displaying invalid email entries:\n\n";
    bool any = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        any = false;
        string e = classRosterArray[i]->getEmail();
        if (e.find('@')==string::npos || e.find('.') == string::npos || e.find(' ') != string::npos)
        {
            cout << e <<"\n";
            any = true;
        }
  /*      for (int j = 0; j < Student::dayArraySize; j++)
        {
            if (e[j] < 0)
            {
                any = true;
                cout << "Student: " << classRosterArray[i]->getID() << ",  Email: ";
                cout << e[j] << " ";
            }
        }*/
       // if (any) cout << "\n"; go to new line between each one that there is

    }
        if (any==false) cout << "No more invalid emails.\n";//if there isnt any inavlid emails, print None
}

void Roster::printByDegType(DegreeType d)
{
    cout << "\n----------------------------------------------- \n\n";
    cout << "Printing Students by Degree Type: " << degreeTypeStrings[d] << "\n\n";
    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getDegType() == d)this->classRosterArray[i]->print();
    }
}

Roster::~Roster()//delete all students 
{
    for (int i = 0; i <= lastIndex; i++)
    {
        delete this->classRosterArray[i];
    }
    delete classRosterArray;
}

int main()
{
    //Add a title to the output
    cout << "\n----------------------------------------------- \n\n";
    cout << "Scripting and Programming - Applications - C867 \n";
    cout << "C++ \n";
    cout << "ID001243438 \n";
    cout << "Menay Wilde \n";
    cout << "\n----------------------------------------------- \n\n";

    int numStudents = 5;
    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Menay,Wilde,mwild33@wgu.edu,27,10,15,20,SOFTWARE"
    };

    Roster* classRoster = new Roster(numStudents);
    cout << "Adding Students and Creating Roster:\t";
    for (int i = 0; i < numStudents; i++) {//add students to roster
        classRoster->parseThenAdd(studentData[i]);
    }
    cout << "Roster Complete. \n";
    cout << "\nDisplaying all Students:\n";
    classRoster->print_All();//display all students

    classRoster->printInvalidEmail();//print any emails that have an error
    cout << "\n----------------------------------------------- \n\n";
    cout << "Printing Average Number of Days in a Course Per Student:\n\n";
    for (int i = 0; i < numStudents; i++) {
        classRoster->printAvgNumDays(classRoster->getStudentAt(i)->getID());
    }

    //print student by their degree type
     //I believe only the software program displayed is wanted. if that is not correct then here is the code to print all 3 degrees
     //    for (int i = 0; i < 3; i++) classRoster->printByDegType((DegreeType)i);
    classRoster->printByDegType((DegreeType)SOFTWARE);

    cout << "\n----------------------------------------------- \n\n";
    cout << "\nRemoving Student A3:\n\n";//remove with student id
    if (classRoster->remove("A3")) {
 //       classRoster->print_All();
        cout << "SUCCESS! Student has been removed.\n";
        numStudents--;
    }
    else cout << "Student not found. \n";

    cout << "\n----------------------------------------------- \n\n";
    cout << "\nRemoving Student A3:\n\n";//remove again to check
    if (classRoster->remove("A3"))
        cout << "SUCCESS! Student has been removed.\n";
    else cout << "Student not found (has already been removed). \n";
    cout << "\n----------------------------------------------- \n\n";

    system("pause");//hold window open
    return 0;
}
