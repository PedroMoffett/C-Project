#include <iostream>
#include <string>
#include "roster.h"

Roster::Roster(){};

Roster::~Roster(){
	for (int i = 0; i < rosterSize; i++){
		delete class_Roster_Array[i];
		class_Roster_Array[i] = nullptr;
	}
};

// Here there is a check to verify that the nullptr is in the class_Roster_Array, then a student object will be created and we add it to the array is there is memory available.
void Roster::add(std::string stud_ID, std::string first_Name, std::string last_Name,
	std::string email_Address, int age, int days_In_Course1, int days_In_Course2,
	int days_In_Course3, DegreeProgram degree_program){
	int daysInCourseArray[daysArray] = {0, 0, 0};
	for (int i = 0; i < rosterSize; i++){
		if (class_Roster_Array[i] == nullptr){
			class_Roster_Array[i] = new Student(stud_ID, first_Name, last_Name, email_Address, age, &daysInCourseArray[daysArray], degree_program);
			class_Roster_Array[i]->set_Days_To_Complete(days_In_Course1, days_In_Course2, days_In_Course3);
			break;
		}
	}
}

void Roster::remove(std::string stud_ID){// Here we are verifying that the student object has been created by stud_ID and we will be deleting it if it does exist, or we will print an error statement that it was not located.
	bool exists = false;
	int index = 0;
	std::cout << "Removing " << stud_ID << ". . ." << std::endl;
	for (int i = 0; i < rosterSize; i++){
		if (class_Roster_Array[i] == nullptr){
		}
		else if (class_Roster_Array[i]->get_Stud_ID() == stud_ID){
			index = i;
			exists = true;
		}
	}
	if (exists){
		delete class_Roster_Array[index];
		class_Roster_Array[index] = nullptr;
		std::cout << "Student with ID " << stud_ID << " has been removed." << std::endl;
	}
	else{
		std::cout << "Student with ID " << stud_ID << " is not found." << std::endl;
	}
}
void Roster::printAll(){// The array will be looped through and print the information for the individual students.
	for (int i = 0; i < rosterSize; i++)
	{
		if (class_Roster_Array[i] != nullptr)
		{
			class_Roster_Array[i]->print();
		}
	}
}

void Roster::printAverageDaysInCourse(std::string stud_ID){// Here we will use stud_ID_from_Roster() to find the studID and print the average days with a course that the student object displays.
	int index = 0;
	float average = 0.0;
	int tempArray[daysArray] = {};
	for (int i = 0; i < rosterSize; i++)
	{
		if (class_Roster_Array[i] != nullptr)
		{
			if (class_Roster_Array[i]->get_Stud_ID() == stud_ID)
			{
				index = i;
			}
		}
	}
	for (int i = 0; i < daysArray; i++)
	{
		tempArray[i] = class_Roster_Array[index]->get_Days_To_Complete(i);
	}
	for (int i = 0; i < daysArray; i++)
	{
		average += static_cast<float>(tempArray[i]);
	}
	average /= daysArray;
	std::cout << stud_ID << " Average days in class: " << average << std::endl;
}

// Here we will check that the emails are correct and if an email is incorrect it will be shown.
// Correct emails are labeled as correct because they meet the proper criteria.
void Roster::printInvalidEmails(){
	std::string email;
	char at = '@';
	char spc = ' ';
	char per = '.';
	for (int i = 0; i < rosterSize; i++){
		if (class_Roster_Array[i] != nullptr){
			email = class_Roster_Array[i]->get_Email_Address();
			if (email.find(spc) != std::string::npos){
				std::cout << email << std::endl;
			}
			else if (email.find(at) == std::string::npos || email.find(per) == std::string::npos){
				std::cout << email << std::endl;
			}
		}
	}
}
void Roster::printByDegreeProgram(DegreeProgram degree_Printed){// All students with the same Degree Program enumeration will be printed.
	for (int i = 0; i < rosterSize; i++){
		if (class_Roster_Array[i] == nullptr){
		}
		else if (class_Roster_Array[i]->get_Degree_Program() == degree_Printed){
			class_Roster_Array[i]->print();
		}
	}
}
void Roster::set_Roster_To_Nullptr(){// Set all of "i" within the array equal to nullptr.
	for (int i = 0; i < rosterSize; i++){
		if (class_Roster_Array[i] != nullptr){
			class_Roster_Array[i] = nullptr;
		}
	}
}
std::string Roster::stud_ID_from_Roster(int index){ // The roster object will have stud_ID accessible.
	if (class_Roster_Array[index] != nullptr){
		return class_Roster_Array[index]->get_Stud_ID();
	}
}