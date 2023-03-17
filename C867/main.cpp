#include <iostream>
#include "Student.h"
#include "Degree.h"
#include "Roster.h"
using namespace std;

int main()
{
	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Student ID: 010340359" << endl;
	cout << "By: Peter Moffett" << endl;
	cout << endl;

	Roster classRoster; //Creates roster class 

	//Prints the roster
	cout << "Displaying Students: \n" << endl;
	classRoster.printAll();
	cout << endl;

	//Displays invalid emails
	cout << "Displaying Bad Emails: \n" << endl;
	classRoster.printBadEmails();
	cout << endl;			  

	//Prints average days in course for each ID
	classRoster.printDaysToComplete("A1");
	classRoster.printDaysToComplete("A2");
	classRoster.printDaysToComplete("A3");
	classRoster.printDaysToComplete("A4");
	classRoster.printDaysToComplete("A5");
	cout << endl;	

	//Prints students in SOFTWARE degree program
	classRoster.printDegree(SOFTWARE);
	cout << endl;	

	//Terminating ID A3	
	cout << "Removing A3." << endl;
	classRoster.remove("A3");

	//Prints the current roster again
	cout << endl;
	classRoster.printAll();
	cout << endl;

	//Removes A3 again, outputs error
	cout << "Removing A3, again. \n" << endl;
	classRoster.remove("A3");
	cout << endl;

	return(0);
}