#include <string>   // Needed for strings
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream> 
#include <vector>
#include "database.h"

using namespace JFFMAH001;
using namespace std;

vector<StudentRecord> database;


void JFFMAH001::add_student(std::string name, std::string surname, std::string stu_no, std::string class_record){ // when defining function you still need to put JFFMAH001:: there onyl when called you don't
	int flag = 0;
	for (vector<StudentRecord>::iterator it = database.begin() ; it != database.end() ; ++it){
		if (stu_no == (*it).stu_no){
			(*it).name = name;
			(*it).surname = surname;
			(*it).class_record = class_record;
			flag = 1;
		}
	}
	if (flag == 0){
		StudentRecord student;	
		student.name = name;
		student.surname = surname;
		student.stu_no = stu_no;
		student.class_record = class_record;
		database.push_back(student);
	}
}

void JFFMAH001::tester(void){
	for (vector<StudentRecord>::iterator it = database.begin() ; it != database.end() ; ++it){
		std::cout << (*it).name << endl;
	}
}
// when defining function you still need to put JFFMAH001:: there only when called you don't

void JFFMAH001::read_database(string filename){
	ifstream in(filename.c_str());
	if(!in) { 
		cout << "Couldn't open " << filename << endl; 
	}else{
		std::string line;
		while (std::getline(in, line, '\n')){
			std::stringstream ss(line); // seperated line by line

			std::string student_name;
			std::string student_surname;
			std::string student_num;
			std::string class_record;
			ss >> student_name;
			ss >> student_surname;
			ss >> student_num;

			std::string token;
			while (std::getline(ss, token, ' ')){ // seperated word by word
				class_record.append(token);
				class_record.append(" "); 
			}

			class_record.erase(0,1);
			add_student(student_name, student_surname, student_num, class_record);
		}
	}
}

void JFFMAH001::save_database(string filename){
	ofstream myfile;
	myfile.open (filename);
	for (vector<StudentRecord>::iterator it = database.begin() ; it != database.end() ; ++it){
		myfile << (*it).name << " "; 
		myfile << (*it).surname << " "; 
		myfile << (*it).stu_no << " ";
		myfile << (*it).class_record << endl;
	}
	myfile.close();
}

void JFFMAH001::display_data(string student_num){
	for (vector<StudentRecord>::iterator it = database.begin() ; it != database.end() ; ++it){
		if (student_num == (*it).stu_no){
			std::cout << (*it).name << " "; 
			std::cout << (*it).surname << " "; 
			std::cout << (*it).stu_no << " ";
			std::cout << (*it).class_record << endl;
		}	
	}
}

void JFFMAH001::grade_student(string student_num){
	std::string token;
	for (vector<StudentRecord>::iterator it = database.begin() ; it != database.end() ; ++it){
		if (student_num == (*it).stu_no){
			token = (*it).class_record;
		}	
	}
	std::stringstream ss(token);
	float count = 0.0;
	int mark = 0;
	string temp;
	while (std::getline(ss, temp, ' ')){
				mark = mark + stoi(temp);
				count = count + 1; 
	}
	float average = mark/count;
	cout << "The average for " << student_num << " is " << average << endl;
}

void JFFMAH001::clear_screen(void){
	system("clear");
}


