#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"classroom.h"
using namespace std;

int main()
{
    Classroom classroom;
    while(1)
    {
        int key;
        cout << "Press 1 if you are the class administration and want to add a new student\n"
             << "Press 2 if you are the class administration and want to add a new teacher\n"
             << "Press 3 if you are a teacher and you want to add marks\n"
             << "Press 4 if you are a teacher and you want to subtract marks\n"
             << "Press 5 if you are a teacher and you want to teach a new course\n"
             << "Press 6 if you are a teacher and you want to stop teaching a course\n"
             << "Press 7 if you are a student and you want to view your marks\n"
             << "Press 8 if you are the class administration and want to remove a student\n"
             << "Press 9 if you are the class administration and want to remove a teacher\n"
             << "Press 10 to exit\n";
        cin >> key;
        string roll_number,name,course;
        int index,index1;
        switch(key)
        {
            case 1: cout << "Enter the roll number of the student\n";
                    cin >> roll_number;
                    classroom.admit_student(roll_number);
                    break;
            case 2: cout << "Enter the name of the teacher\n";
                    cin >> name;
                    classroom.add_teacher(name);
                    break;
            case 3: cout << "Enter your name\n";
                    cin >> name;
                    index = classroom.find_teacher(name);
                    if(index == -1)
                    cout << "You are not a teacher in this class\n";
                    else
                    {
                        Teacher& t = classroom.get_teacher(index);
                        cout << "Enter the course in which you want to add marks\n";
                        cin >> course;
                        t.add_marks(classroom,course);
                    }
                    break;
            case 4: cout << "Enter your name\n";
                    cin >> name;
                    index = classroom.find_teacher(name);
                    if(index == -1)
                    cout << "You are not a teacher in this class\n";
                    else
                    {
                        Teacher t = classroom.get_teacher(index);
                        cout << "Enter the course in which you want to subtract marks\n";
                        cin >> course;
                        t.subtract_marks(classroom,course);
                    }
                    break;
            case 5: cout << "Enter your name\n";
                    cin >> name;
                    index = classroom.find_teacher(name);
                    if(index == -1)
                    cout << "You are not a teacher in this class\n";
                    else
                    {
                        Teacher& t = classroom.get_teacher(index);
                        t.add_course(classroom);
                    }
                    break;
            case 6: cout << "Enter your name\n";
                    cin >> name;
                    index = classroom.find_teacher(name);
                    if(index == -1)
                    cout << "You are not a teacher in this class\n";
                    else
                    {
                        Teacher& t = classroom.get_teacher(index);
                        t.drop_course(classroom);
                    }
                    break;
            case 7: cout << "Enter your roll number\n";
                    cin >> roll_number;
                    index = classroom.find_student(roll_number);
                    if(index == -1)
                    cout << "You are not a student in this class\n";
                    else
                    {
                        Student s = classroom.get_student(index);
                        cout << "Enter the course in which you want to see your marks\n";
                        cin >> course;
                        index1 = classroom.search_course(course);
                        if(index1 == -1)
                        cout << "you are not enrolled in this course\n";
                        else
                        cout << "Your marks are " << classroom.get_marks(course,index,index1) << "\n";
                    }
                    break;
            case 8: cout << "Enter the roll number of the student whom you want to remove\n";
                    cin >> roll_number;
                    classroom.remove_student(roll_number);
                    break;
            case 9: cout << "Enter the name of the teacher whom you want to remove\n";
                    cin >> name;
                    classroom.remove_teacher(name);
                    break;
            case 10: exit(EXIT_SUCCESS);
            default : cout << "Enter a valid key\n";
        }
    }
}