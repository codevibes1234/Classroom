#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include"classroom.h"
using namespace std;

Teacher :: Teacher(Classroom classroom, string nam)
{
    name = nam;
    cout << "Enter the number of courses that the teacher teaches\n";
    int num;
    cin >> num;
    cout << "Enter the names of the courses one after the other\n";
    for(int i = 0; i < num; i++)
    {
        string temp;
        cin >> temp;
        Course.push_back(temp);
    }
    for(int i = 0; i < Course.size(); i++)
    for(int j = 0; j < (classroom.student).size(); j++)
    marks_register[Course[i]].push_back(make_pair(((classroom.student)[j]).roll_number,0));
    cout << "Teacher added successfully\n";
}

int Teacher :: find_course(string course)
{
    bool flag = false;
    int i;
    for(i = 0; i < Course.size(); i++)
    {
        if(Course[i] == course)
        {
            flag = true;
            break;
        }
    }
    if(!flag)
    return -1;
    else
    return i;
}

void Teacher :: add_marks(Classroom classroom, string course)
{
    int index = this -> find_course(course);
    if(index == -1)
    {
        cout << "You don't teach this course\n";
        return;
    }
    cout << "Enter the roll number of the student\n";
    string roll_number;
    cin >> roll_number;
    index = classroom.find_student(roll_number);
    if(index == -1)
    {
        cout << "There is no student with this roll number\n";
        return;
    }
    cout << "Enter the number of marks that you want to add\n";
    int value;
    cin >> value;
    if(((marks_register[course])[index]).second + value > 100)
    {
        cout << "You cant add these marks since the total marks become more than 100 after adding this\n";
        return;
    }
    ((marks_register[course])[index]).second += value;
    cout << "Marks added successfully\n";
}

void Teacher :: subtract_marks(Classroom& classroom, string course)
{
    int index = this -> find_course(course);
    if(index == -1)
    {
        cout << "You don't teach this course\n";
        return;
    }
    cout << "Enter the roll number of the student\n";
    string roll_number;
    cin >> roll_number;
    index = classroom.find_student(roll_number);
    if(index == -1)
    {
        cout << "There is no student with this roll number\n";
        return;
    }
    cout << "Enter the number of marks that you want to subtract\n";
    int value;
    cin >> value;
    if(((marks_register[course])[index]).second - value < 0)
    {
        cout << "You cant subtract these marks since the total marks become negative after subtracting this\n";
        return;
    }
    ((marks_register[course])[index]).second -= value;
    cout << "Marks subtracted successfully\n";
}

void Teacher :: add_course(Classroom& classroom)
{
    cout << "Enter the course which you want to teach\n";
    string course;
    cin >> course;
    int index = -1;
    int i;
    for(i = 0; i < (classroom.teacher).size(); i++)
    {
        index = ((classroom.teacher)[i]).find_course(course);
        if(index != -1)
        break;
    }
    if(index == -1)
    {
        Course.push_back(course);
        for(i = 0; i < (classroom.student).size(); i++)
        marks_register[course].push_back(make_pair(((classroom.student)[i]).roll_number,0));
        cout << "Course added successfully\n";
    }
    else
    {
        if(this == &(classroom.teacher[i]))
        cout << "You already teach this course\n";
        else
        cout << "Someone else already teaches this course\n";
    }
}

void Teacher :: drop_course(Classroom& classroom)
{
    cout << "Enter the course which you want to stop teaching\n";
    string course;
    cin >> course;
    int index = this->find_course(course);
    if(index == -1)
    {
        cout << "You don't teach this course\n";
        return;
    }
    marks_register.erase(Course[index]);
    auto itr = Course.begin()+index;
    Course.erase(itr);
    cout << "Course dropped successfully\n"; 
}

int Classroom :: find_student(string roll)
{
    bool flag = false;
    int i;
    for(i = 0; i < student.size(); i++)
    {
        if(student[i].roll_number == roll)
        {
            flag = true;
            break;
        }
    }
    if(!flag)
    return -1;
    else
    return i;
}

int Classroom :: search_course(string course)
{
    int ret = -1;
    for(int i = 0; i < teacher.size(); i++)
    for(int j = 0; j < (teacher[i].Course).size(); j++)
    if(course == (teacher[i].Course)[j])
    ret = i;
    return ret;
}

int Classroom :: get_marks(string course, int index, int index1)
{
    return (((teacher[index1]).marks_register)[course])[index].second;
}

void Classroom :: admit_student(string roll)
{
    int index = this->find_student(roll);
    if(index != -1)
    {
        cout << "There is already a student with this roll number\n";
        return ;
    }
    Student s(roll);
    for(int i = 0; i < teacher.size(); i++)
    for(auto j = (teacher[i].marks_register).begin(); j != (teacher[i].marks_register).end(); j++)
    (j->second).push_back(make_pair(roll,0));
    student.push_back(s);
}

void Classroom :: remove_student(string roll)
{
    int index = this->find_student(roll);
    if(index == -1)
    {
        cout << "There is no student with this roll number\n";
        return;
    }
    for(int i = 0; i < teacher.size(); i++)
    {
        for(auto j = (teacher[i].marks_register).begin(); j != (teacher[i].marks_register).end(); j++)
        {
            auto itr = (j -> second).begin()+index;
            (j -> second).erase(itr);
        }
    }
    auto itr = student.begin()+index;
    student.erase(itr);
    cout << "Student removed successfully\n";
}

int Classroom :: find_teacher(string name)
{
    bool flag = false;
    int i;
    for(i = 0; i < teacher.size(); i++)
    {
        if(teacher[i].get_name() == name)
        {
            flag = true;
            break;
        }
    }
    if(!flag)
    return -1;
    else
    return i;
}

void Classroom :: add_teacher(string name)
{
    int index = this->find_teacher(name);
    if(index != -1)
    {
        cout << "There is already a teacher with this name\n";
        return ;
    }
    Teacher t(*this,name);
    teacher.push_back(t);
}

void Classroom :: remove_teacher(string name)
{
    int index = this->find_teacher(name);
    if(index == -1)
    {
        cout << "There is no teacher with this name\n";
        return;
    }
    auto itr = teacher.begin()+index;
    teacher.erase(itr);
    cout << "Teacher removed successfully\n";
}