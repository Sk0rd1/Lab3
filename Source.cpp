#include <iostream>
#include <fstream>
#include <string>
#include <utility>
using namespace std;

class Student
{
	string surname, name;
	int scores_maths, scores_it, scores_physics;
public:
	Student();
	~Student();
	Student(string, string, int, int, int);
	void set_surname(string);
	void set_name(string);
	void set_scores_maths(int);
	void set_scores_it(int);
	void set_scores_physics(int);
	friend bool comparison(int, int, int, Student);
	string get_surname();
	string get_name();
	int get_scores_maths();
	int get_scores_it();
	int get_scores_physics();
	void print();
};

Student::Student()
{

	this->surname = "-";
	this->name = "-";
	this->scores_maths = 0;
	this->scores_it = 0;
	this->scores_physics = 0;
}

Student::~Student() {}

Student::Student(string surname, string name, int scores_maths, int scores_it, int scores_physics)
{
	this->surname = surname;
	this->name = name;
	this->scores_maths = scores_maths;
	this->scores_it = scores_it;
	this->scores_physics = scores_physics;
}

void Student::set_surname(string a)
{
	this->surname = a;
}

void Student::set_name(string a)
{
	this->name = a;
}

void Student::set_scores_maths(int a)
{
	this->scores_maths = a;
}

void Student::set_scores_it(int a)
{
	this->scores_it = a;
}

void Student::set_scores_physics(int a)
{
	this->scores_physics = a;
}

bool comparison(int result_maths, int result_it, int result_physics, Student one_student)
{
	if (result_maths + result_it + result_physics > one_student.scores_maths + one_student.scores_it + one_student.scores_physics)
		return true;
	else
		return false;
}

void Student::print()
{
	cout << " " << surname << " " << name << " " << scores_maths << " " << scores_it << " " << scores_physics << " [ " << double(scores_maths + scores_it + scores_physics)/3 << " ] " << endl;
}

string Student::get_surname()
{
	return this->surname;
}

string Student::get_name()
{
	return this->name;
}

int Student::get_scores_maths()
{
	return this->scores_maths;
}

int Student::get_scores_it()
{
	return this->scores_it;
}

int Student::get_scores_physics()
{
	return this->scores_physics;
}

int main()
{
	int num = 0;
	string str;
	const int SIZE = 3;
	ifstream file("data.txt");
	while (!file.eof())
	{
		getline(file, str, '\n');
		num++;
	}
	Student* total_students = new Student[SIZE];
	file.clear();
	file.seekg(0);

	int result_maths, result_it, result_physics, r_m, r_i, r_p;
	string name, surname, r_s, r_n;
	for (int i = 0; i < num; i++)
	{
		file >> surname >> name >> result_maths >> result_it >> result_physics;
		for (int j = 0; j < SIZE; j++)
		{

			if (comparison(result_maths, result_it, result_physics, total_students[j]))
			{
				r_s = total_students[j].get_surname();
				r_n = total_students[j].get_name();
				r_m = total_students[j].get_scores_maths();
				r_i = total_students[j].get_scores_it();
				r_p = total_students[j].get_scores_physics();

				total_students[j].set_surname(surname);
				total_students[j].set_name(name);
				total_students[j].set_scores_maths(result_maths);
				total_students[j].set_scores_it(result_it);
				total_students[j].set_scores_physics(result_physics);

				surname = r_s;
				name = r_n;
				result_maths = r_m;
				result_it = r_i;
				result_physics = r_p;
			}
		}
		
	}
	for (int i = 0; i < SIZE; i++)
	{
		total_students[i].print();
	}
	delete[] total_students;
}