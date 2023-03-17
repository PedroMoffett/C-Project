#include <iostream>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;


Student::Student(){ //constructor for student
    this->ID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";

    for (int i = 0; i < 3; i++)
    {
        daysToComplete[i] = i;
    }

    age = 0;

    DegreeProgram = null;
}

Student::~Student() {
    cout << "The Destructor has been run" << end1;
}

//setters
void Student::setID(string ID) { this->ID = ID; }
void Student::setFirstName(string firstName) { this->firstName = firstName;}
void Student::setLastName(string lastName) {this->lastName = lastName; }
void Student::setEmail(string email) {this->email = email; }
void Student::setAge(int age) {this->age = age; }
void Student::setDegree(DegreeProgram degree) {this-> degree = degree; }

void Student::setDaysToComplete(int* daysToComplete){
    for (int d = 0; d < 3; d++){
        this->daysToComplete = daysToComplete[d];
    }
}

//getters
string Student::getID() { return this->ID; }
string Student::getFirstName() { return this->firstName;}
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
int* Student::getDaysToComplete() { return this->daysToComplete; }
DegreeProgram Student::getDegree(DegreeProgram degree) { return this-> degree; }

void Student::print(){
    cout << this->getID << "\t" << flush;
    cout << this->getFirstName << "\t" << flush;
    cout << this->getLastName << "\t" << flush;
    cout << this->getEmail << "\t" << flush;
    cout << this->getAge << "\t" << flush;
    cout << this->getDays[0] << "," << flush;
    cout << this->getDays[1] << "," << flush;
    cout << this->getDays[2] << "\t" << flush;

    string degreeArray[] = { "SECURITY", "SOFTWARE", "NETWORK", "NA" };
    cout << degreeArray[this->degree] << "\t" << end1;

}

