#include "student.h"

Student::Student(std::string student_ID, std::string f_Name, std::string l_Name,
	std::string email_Address, int age, int days_In_Course[daysArray], DegreeProgram degree_program){
	this->stud_ID = student_ID;
	this->first_Name = f_Name;
	this->last_Name = l_Name;
	this->email_Address = email_Address;
	this->age = age;
	for (int i = 0; i < daysArray; i++) {
		this->Days_In_Course[i] = days_In_Course[i];
	}
	this->degree_Program = degree_program;
}

Student::~Student() {};

std::string Student::get_Stud_ID(){
	return stud_ID;
}

std::string Student::get_First_Name(){
	return first_Name;
}

std::string Student::get_Last_Name(){
	return last_Name;
}

std::string Student::get_Email_Address(){
	return email_Address;
}

int Student::get_Age(){
	return age;
}

int Student::get_Days_To_Complete(int index){
	return Days_In_Course[index];
}

DegreeProgram Student::get_Degree_Program(){
	return degree_Program;
}

void Student::print(){// This will print the correct student data as shown below
	std::cout << stud_ID << "\tFirst Name: " << first_Name << "\tLast Name: " << last_Name << "\tAge: " << age << "\tDays in course: " << "{"<< Days_In_Course[0] << ", " << Days_In_Course[1] << ", " << Days_In_Course[2] << "} " << "Degree Program: " << stringify_Enumeration(get_Degree_Program()) << std::endl;
}
void Student::set_Stud_ID(std::string newID){
	stud_ID = newID;
}
void Student::set_First_Name(std::string newFname){
	first_Name = newFname;
}
void Student::set_Last_Name(std::string newLname){
	last_Name = newLname;
}
void Student::set_Email_Address(std::string newEmail){
	email_Address = newEmail;
}
void Student::set_Age(int newAge){
	age = newAge;
}
void Student::set_Days_To_Complete(int days1, int days2, int days3){// Allocates the days to the correct index within the array
	Days_In_Course[0] = days1;
	Days_In_Course[1] = days2;
	Days_In_Course[2] = days3;
}
void Student::set_Degree_Program(DegreeProgram degree){
	degree_Program = degree;
}
std::string Student::stringify_Enumeration(DegreeProgram degree){//The Degree Program enumaration will return as a string.
	switch (degree)
	{
	case SECURITY:
		return "Security";
	case NETWORK:
		return "Network";
	case SOFTWARE:
		return "Software";
	}
}