#pragma once
#include "degree.h"
#include "student.h"

const int rosterSize = 5;

class Roster
{
	public:
		Roster();
		~Roster();
		void add(std::string stud_ID, std::string first_Name, std::string last_Name,
			std::string email_Address, int age, int days_In_Course1, int days_In_Course2,
			int days_In_Course3, DegreeProgram degree_program);
		void remove(std::string studentID);
		void printAll();
		void printAverageDaysInCourse(std::string stud_ID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degree_Printed);
		std::string stud_ID_from_Roster(int index);
	private:
		void set_Roster_To_Nullptr();
		Student* class_Roster_Array[rosterSize] = {nullptr, nullptr, nullptr, nullptr, nullptr};

};