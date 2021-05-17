
#ifndef DATABASE_H
#define DATABASE_H
#include <string>
//any includes here

namespace JFFMAH001 {
void add_student(std::string name, std::string surname, std::string stu_no, std::string class_record);
void read_database(std::string filename);
void save_database(std::string filename);
void display_data(std::string student_num);
void grade_student(std::string class_record);
void clear_screen(void);
void tester(void);
}

struct StudentRecord{
	std::string name;
	std::string surname;
	std::string stu_no;
	std::string class_record;
};

#endif