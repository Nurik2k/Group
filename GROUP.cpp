TEACHER.H
#pragma once
#include <string>
#include <ostream>
using namespace std;

class teacher
{
public:
	teacher(const char* nm, const char* grp);
	string get_name();
	string get_group1();
	bool equal(const teacher tc);
	friend ostream& operator<<(ostream& os, const teacher& tc);
private:
	string name;
	string group1;
};
TEACHER.CPP
#include "teacher.h"

teacher::teacher(const char* nm, const char* grp)
{
	name = nm;
	group1 = grp;
}

string teacher::get_name()
{
	return name;
}

string teacher::get_group1()
{
	return group1;
}

bool teacher::equal(const teacher tc)
{
	return name==tc.name && group1 ==tc.group1;
}

ostream& operator<<(ostream& os, const teacher& tc){
	os << "<" << tc.name << "> - <" << tc.group1 << ">";
	return os;
}

STUDENT.H
#pragma once
#include <string>
#include <ostream>
using namespace std;

class student
{
public:
	student(const char* nm, const char* grp);
	string get_namest();
	string get_groupst();
	bool equalst(const student st);
	friend ostream& operator<<(ostream& os, const student& st);
private:
	string namest;
	string last_namest;
};


STUDENT.CPP
#include "student.h"

student::student(const char* nm, const char* grp)
{
	namest = nm;
	last_namest = grp;
}

string student::get_namest()
{
	return namest;
}

string student::get_groupst()
{
	return last_namest;
}

bool student::equalst(const student st)
{
	return namest == st.namest && last_namest == st.last_namest;
}

ostream& operator<<(ostream& os, const student& st)
{
	os << "<" << st.namest << "> - <" << st.last_namest << ">";
	return os;
}

GROUP.H
#pragma once
#include<iostream>
#include<vector>
#include "teacher.h"
#include "student.h"
using namespace std;
class group
{

	vector<teacher> teacher1 ;
	vector<student>students;
public:
	void add(teacher tc);
	void add1(student st);
	void remove(teacher tc);
	void remove1(student st);
	friend std::ostream& operator<<(std::ostream& os, const group grpr);
	



};

GROUP.CPP
#include "group.h"

void group::add(teacher tc)
{
	teacher1.push_back(tc);
	
}

void group::add1(student st)
{
	students.push_back(st);
}

void group::remove(teacher tc)
{
	auto size = teacher1.size();
	std::vector<teacher> vs;
	for (auto i = 0; i < size; i++)
		if (!teacher1[i].equal(tc))
			vs.push_back(teacher1[i]);
	teacher1 = vs;
}

void group::remove1(student st)
{
	auto size = students.size();
	std::vector<student> vs;
	for (auto i = 0; i < size; i++)
		if (!students[i].equalst(st))
			vs.push_back(students[i]);
	students = vs;
}

std::ostream& operator<<(std::ostream& os, const group grpr)
{
	auto size = grpr.teacher1.size();
	for (auto i = 0; i < size; i++)
		os << grpr.teacher1[i] << std::endl;

	auto size1 = grpr.students.size();
	for (auto i = 0; i < size1; i++)
		os << grpr.students[i] << std::endl;

	return os;
}
INT MAIN
#include <iostream>
#include "group.h"
#include "student.h"
#include "teacher.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	group group1;
	
	teacher first("Группа: 202", "Ерофеев Юрий");
	group1.add(first);
	
	cout << group1;
	cout << "---------------------" << endl;
	group1.add1(student("Сейсенбай", " Нуржан"));
	group1.add1(student("Дюсембаева", "Камиля"));
	group1.add1(student("Безверхова", "Екатерина"));
	group1.remove(first);
	cout << group1 << endl;
	
} 
