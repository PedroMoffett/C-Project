#pragma once
#include <iostream>
#include "degree.h"
#include <string>

const int daysArray = 3;

class Student {
	public:
		Student(std::string stud_ID, std::string f_name, std::string l_name,
			std::string email_Address, int age, int days_In_Course[daysArray], DegreeProgram degree_Program);
		~Student();
		std::string get_Stud_ID();
		std::string get_First_Name();
		std::string get_Last_Name();
		std::string get_Email_Address();
		int get_Age();
		int get_Days_To_Complete(int index);
		DegreeProgram get_Degree_Program();
		void print();

		std::string stringify_Enumeration(DegreeProgram degree);
		void set_Stud_ID(std::string new_ID);
		void set_First_Name(std::string f_Name);
		void set_Last_Name(std::string l_Name);
		void set_Email_Address(std::string email);
		void set_Age(int newAge);
		void set_Days_To_Complete(int days_1, int days_2, int days_3);
		void set_Degree_Program(DegreeProgram degree);
	private:
		std::string stud_ID;
		std::string first_Name;
		std::string last_Name;
		std::string email_Address;
		int age;
		int Days_In_Course[daysArray] = {};
		DegreeProgram degree_Program;
};