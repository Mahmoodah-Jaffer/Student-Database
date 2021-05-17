#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "database.h"

int main(){
	using namespace JFFMAH001;
	using namespace std;
	char option;
	std::string student_name;
	std::string student_surname;
	std::string student_num;
	std::string class_record;

	for(;;){
		cout << "0: Add student" << endl;
		cout << "1: Read database" << endl;
		cout << "2: Save database" << endl;
		cout << "3: Display given student data" << endl;
		cout << "4: Grade student" << endl;
		cout << "q: Quit" << endl;
		cout << "Enter a number (or q to quit) and press return" << endl;

		cin >> option;
		
		if(option == 'q'){
			break;

		}else if (option == '0'){
			clear_screen();
			cin.ignore();
			std::string temp;
			string student_info;
			getline(cin, temp);
			stringstream ss(temp);

			ss >> student_name;
			ss >> student_surname;
			ss >> student_num;

			while(getline(ss, student_info, ' ')){
				class_record.append(student_info);
				class_record.append(" ");
			}
			class_record.erase(0,1);
			add_student(student_name, student_surname, student_num, class_record);
			class_record = "";// clears class record for next user
			clear_screen();

		}else if (option == '1'){
			clear_screen();
			cout << "Name of file to read from: ";
			cin.ignore();
			std::string filename;
			getline(cin, filename);
			read_database(filename);
			clear_screen();
		}else if (option == '2'){
			clear_screen();
			cout << "Name of file to save to: ";
			cin.ignore();
			std::string filename;
			getline(cin, filename);
			save_database(filename);
			clear_screen();
		}else if (option == '3'){
			clear_screen();
			cin.ignore();
			std::string temp;
			getline(cin, temp);
			display_data(temp);
		}else if (option == '4'){
			clear_screen();
			cin.ignore();
			std::string temp;
			getline(cin, temp);
			grade_student(temp);
		}
		else if(option == 't'){
			tester();
		}else{
			clear_screen();
			cout << "Invalid option. Please enter a number (or q to quit) and press return" << endl;
		}
	}
	return 0;

}
