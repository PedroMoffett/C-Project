#pragma once
#include "degree.h"
using namespace std;

class Student{
    private:
        string numID;
        string firstName;
        string lastName;
        int age;
        int daysToComplete
        DegreeProgram degree;

    public:
        //Constructor
        Student();
        //Decstructor
        ~Student();

        //setters
        void setID(string ID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmail(string email);
        void setAge(int age);
        void setDays(int* daysToComplete);
        void setDegreeProgram(string degree);

        //getters
        string getID();
        string getFirstName();
        string getLastName();
        string getEmail();
        int getAge();
        int getDaysToComplete();
        DegreeProgram Degree();

        void Print();
        

}