#pragma once
#include "student.h"
using namespace std;

class Roster
{
    private:
    
    //no values

    public:
    Roster();

    ~Roster();

    Student* rosterArray[5];


    void add(string ID, string firstName, string lastName, string email, int age, int daysToCompleteCourse1, int daysToCompleteCourse2, int daysToCompleteCourse3, DegreeProgram degree);
    void remove(string removeID);
    void printAll();
    void printDaysInCourse(string ID);
    void printBadEmails();
    void printAccordingToDegreeProgram(DegreeProgram printdegree);

};
