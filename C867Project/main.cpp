#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"

const int dataSize = 5;
const int tempDataArraySize = 9;
const std::string courseInfo = "Course Name: Scripting and Programming Applications(C867)\nLanguage used: C++\nStudent ID: #010340359\nStudent name: Peter Moffett\n";
const std::string studentData[dataSize] ={
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Peter,Moffett,pmoffe6@wgu.edu,24,11,58,17,SOFTWARE"
};

std::string tempDataArray[tempDataArraySize] = {};

void parseData(std::string inString); // Parse values seperated by commas from a string and store those values into the array. tempDataArray[].

int main(){
	
	std::cout << courseInfo << std::endl; // Course information will be displayed.

	Roster classRoster = Roster(); // An instance called classRoster is being created.

	std::cout << "Class Roster is generating.  Please hold..." << std::endl;

	for (int i = 0; i < dataSize; i++){
		parseData(studentData[i]);
		std::string tempStudid, tempFirstName, tempLastName, tempEmail;
		int tempAge, tempDay1, tempDay2, tempDay3;
		DegreeProgram tempDegreeProgram;
		tempStudid = tempDataArray[0];
		tempFirstName = tempDataArray[1];
		tempLastName = tempDataArray[2];
		tempEmail = tempDataArray[3];
		tempAge = stoi(tempDataArray[4]);
		tempDay1 = stoi(tempDataArray[5]);
		tempDay2 = stoi(tempDataArray[6]);
		tempDay3 = stoi(tempDataArray[7]);
		if (tempDataArray[8] == "SECURITY"){
			tempDegreeProgram = SECURITY;
		}
		else if (tempDataArray[8] == "NETWORK"){
			tempDegreeProgram = NETWORK;
		}
		else if (tempDataArray[8] == "SOFTWARE"){
			tempDegreeProgram = SOFTWARE;
		}
		else{
			tempDegreeProgram = HISTORY;
		}

		classRoster.add(tempStudid, tempFirstName, tempLastName, tempEmail, tempAge, tempDay1, tempDay2, tempDay3, tempDegreeProgram);
	}

	std::cout << "\nClass Roster is now in the process of being printed" << std::endl;

	classRoster.printAll(); 	//The Roster is being looped through and all student data is being printed.

	std::cout << "\nInvalid email addresses are now in the process of being printed" << std::endl;

	classRoster.printInvalidEmails(); 	//The Roster is being looped through and all invalid emails are being printed.

	std::cout << "\nThe average days in an individual course for each student are now being printed" << std::endl;

	for (int i = 0; i < dataSize; i++){ 	//The Roster is being looped through and all student's average days in the course are being printed.
		classRoster.printAverageDaysInCourse(classRoster.stud_ID_from_Roster(i));
	}

	std::cout << "\nAll students registered under the Software program are now in the process of being printed" << std::endl;

	classRoster.printByDegreeProgram(SOFTWARE);  //Students under the SOFTWARE program are being printed

	std::cout << std::endl;

	classRoster.remove("A3"); //Students with the "A3" ID are going to be removed

	std::cout << "\nPrinting class roster. . ." << std::endl;

	classRoster.printAll();//Here were are demonstrating the the student has been removed

	std::cout << std::endl;

	classRoster.remove("A3");//This will display an error since this student is already removed from the Roster

	classRoster.~Roster();//The destructor is removing dynamically allocated memory from the roster
}
void parseData(std::string inString){
	std::string container = inString;
	std::istringstream inSS(container);
	std::string token;
	int i = 0;
	while (getline(inSS, token, ',')){
		tempDataArray[i] = token;
		i++;
	}
}