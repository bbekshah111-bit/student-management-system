#include<iostream>

using namespace std;

class Student
{
    


    public:
        string name;
        int age;
        float gpa;
        int id;

        void display()
        {
            cout << "1.Name: " << name <<"\n";
            cout << "2.Age: " << age << "\n";
            cout << "3.GPA: " << gpa << "\n";
            cout << "4.ID: " << id << "\n";
            cout << "\n\n";
    
        }
};