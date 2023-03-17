#include <iostream>
#include <sstream>
#include <vector>
#include<string>
#include "roster.h"
#include "degree.h"
using namespace std;

const string studentData[] =
{
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Peter,Moffett,pmoffe6@wgu.edu,21,57,32,55,SOFTWARE" 
};

string degreeArray[] = {"SECURITY", "SOFTWARE", "NETWORK", "NA" };

int tableSize = sizeof(studentData) / sizeof(string);

Roster::Roster(){
    for (int i = 0; i<tableSize; i++){
        rosterArray[i] = new Student;

        string tempStudentID, tempFirstName, tempLastName, tempEmail, stringAge, stringDay0, stringDay1, stringDay2, stringDegree;
        int tempAge, tempDay0, tempDay1, tempDay2;
        DegreeProgram tempDegree = NA;

        int tempDaysToComplete[3];

		stringstream inputStream; //A string stream that stores the single line from the student data table to the following string stream in the next line
		inputStream << studentData[i];

		char delimit = ',';

		//Creates a temporary student object to parse the string data
		Student* ptrStudent;
		ptrStudent = new Student;

		//Recieves each item from the string stream as seperated by the delimiting character and then sets it using the setter for the student object
		getline(inputStream, tempID, delimit);
		ptrStudent->setID(tempID);

		getline(inputStream, tempFirstName, delimit);
		ptrStudent->setfirstName(tempFirstName);

		getline(inputStream, tempLastName, delimit);
		ptrStudent->setlastName(tempLastName);

		getline(inputStream, tempEmail, delimit);
		ptrStudent->setEmail(tempEmail);

		getline(inputStream, ageString, delimit);
		tempAge = stoi(ageString);
		ptrStudent->setAge(tempAge);


		//Recieves the total days to complete classes
		getline(inputStream, day0, delimit);
		day0 = stoi(day0);
		daysToComplete[0] = stoi(day0);

		getline(inputStream, day1, delimit);
		day1 = stoi(day1);
		daysToComplete[1] = stoi(day1);

		getline(inputStream, day2, delimit);
		day2 = stoi(day2);
		daysToComplete[2] = stoi(day2;

		//Sets the full days to complete using a populated array
		ptrStudent->setDaysToComplete(tempDaysToComplete);

		//Recieves the string related to the degree
		getline(inputStream, degree, delimit);

		//if-else statements that assign the matching degree program to the enum value
		if (degreeString == "SECURITY")
			tempDegree = SECURITY;
		else if (degreeString == "NETWORK")
			tempDegree = NETWORK;
		else if (degreeString == "SOFTWARE")
			tempDegree = SOFTWARE;
		else
			tempDegree = NA;

		//Sets the enum value for the degree program for the pointer student
		ptrStudent->setDegreeProgram(tempDegree);

		//Sets the temporary student object to the appropriate position in the roster array
		RosterArray[i] = ptrStudent;
	}
}


//Destructor for releasing memory and declares that the destructor has ran
Roster::~Roster() { cout << "Roster Destructor has ran." << endl; }


//Loops through each item and calls the print function from the student method
void Roster::printAll() {
	for (int i = 0; i < table_size; i++) {
		rosterArray[i]->print();
	}
}

void Roster::remove(string removeID) {
	//A boolean flag to determine if the ID has been found
	bool foundFlag = false;

	for (int i = 0; i < tableSize; i++) {
		if (rosterArray[i]->getID() == removeID) {
			foundFlag = true; //Found flag gets set to true

			tableSize = tableSize - 1; //Reduces the table size as we are removing one element

			//Loop starts where the ID was found and shifts every item
			for (int j = i; j < tableSize; j++) {
				rosterArray[j] = rosterArray[j + 1];
			}
		}
	}
	//Reports ID was not found 
	if (foundFlag == false) { cout << "The Student ID was not found" << endl; }
}

void Roster::add(string ID, string firstName, string lastName, string emailAddress, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degree) {
	tableSize++; //Increments table size
	int a = tableSize - 1;

	int daysArray[3]; //Temp array

	//Temp object
	Student* addStudent;
	addStudent = new Student;


	//Setter for strings and age
	addStudent->setID(studentID);
	addStudent->setFirstName(firstName);
	addStudent->setLastName(lastName);
	addStudent->setEmail(email);
	addStudent->setSge(age);

	//Populates temp array with integers given
	daysArray[0] = daysToComplete1;
	daysArray[1] = daysToComplete2;
	daysArray[2] = daysToComplete3;

	//Sets the days to complete array by passing the temporary array to the setter
	addStudent->setDaysToComplete(daysArray);

	//Sets the degree program based on the passed in value
	addStudent->setDegree(degree);

	//Set the new spot in the array to the values of the temporary student
	rosterArray[a] = addStudent;
}

void Roster::printBadEmails() {

	bool validEmail = true;
	bool validChar = true;
	string emailSearch;
	size_t found; //Will point to the position in the string where the character was found or at the end of the string if it was not found

	for (int i = 0; i < tableSize; i++) {

		//Base condition at the start of the for-loop
		validEmail = true;
		validChar = true;

		//Putting the objects email into a string
		emailSearch = RosterArray[i]->getEmail();

		//Looks for the email string @
		found = emailSearch.find("@");

		//Invalid if this is found after the length of the email
		if (found > emailSearch.length()) { validEmail = false; }

		//If @ symbol is located this if statement will then check if the next character is valid
		if (found < emailSearch.length()) {
			found++; //Increments found by one
			validChar = isalnum(emailSearch[found]);
		}

		if (validChar == false) { validEmail = false; } //If a valid character isnt located then the email is invalid

		//Looks in the email string for . (period)
		found = emailSearch.find(".");
		if (found > emailSearch.length()) { validEmail = false; }


		//Looks for a blank spaces in the email string
		found = emailSearch.find(" ");
		if (found < emailSearch.length()) { validEmail = false; }

		//Prints invalid emails
		if (validEmail == false) {
			cout << emailSearch << "\t" << "- is invalid." << endl;

		}
	}
}

void Roster::printDaysInCourse(string ID) {

	for (int i = 0; i < tableSize; i++) {

		int day0, day1, day2; //Int declaration
		double avg;
		string id = RosterArray[i]->getID(); //Gets the student ID based on the loop iteration

		//Assigns the values from the student object to the local integer variable
		day0 = rosterArray[i]->getDaysToComplete()[0];
		day1 = rosterArray[i]->getDaysToComplete()[1];
		day2 = rosterArray[i]->getDaysToComplete()[2];

		avg = (day0 + day1 + day2) / 3.0;

		if (id == ID) {
			cout << "Student ID: " << id << ", average days in course is: - " << avg << endl;

		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreePrint) {

	cout << "Students In " << degreeArray[degreePrint] << " Degree Program:\n" << endl;

	int studentCount = 0;
	DegreeProgram localDegree;

	for (int i = 0; i < tableSize; i++) {

		//Sets a local variable in the function to the value of the degree program for the studen being checked
		localDegree = rosterArray[i]->getDegree();

		//If the student matches then print
		if (localDegree == degreePrint) {

			rosterArray[i]->print();
			studentCount++;
		}
	}
	//Displays a message if no valid students are found
	if (studentCount == 0) { cout << "No valid students found" << endl; }
}
    }
}
