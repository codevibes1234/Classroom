#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Student;
class Classroom;

class Teacher
{
    friend class Classroom;
    private:
    string name;
    vector <string> Course;
    map <string,vector<pair<string,int>>> marks_register;
    public :
    Teacher() {};
    Teacher(Classroom classroom, string nam);
    void add_marks(Classroom classroom, string course);
    void subtract_marks(Classroom& classroom, string course);
    void add_course(Classroom& classroom);
    void drop_course(Classroom& classroom);
    string get_name() {return name;}
    int find_course(string course);
    //Assuming that the marks range from 0 to 100.
};

class Student
{
    friend class Teacher;
    friend class Classroom;
    private:
    string roll_number;
    public:
    Student() {};
    Student(string roll) : roll_number(roll){cout << "Student created successfully\n";}
};

class Classroom
{
    friend class Teacher;
    private:
    //these are the databases containing attributes of students and teachers 
    vector <Teacher> teacher;
    vector <Student> student;
    public:
    void add_teacher(string name);
    void remove_teacher(string name);
    int find_teacher(string name);
    void admit_student(string roll);
    void remove_student(string roll);
    int find_student(string roll);
    int get_marks(string,int,int);
    int search_course(string);
    Teacher& get_teacher(int index) {return teacher[index];}
    Student get_student(int index) {return student[index];}
};


