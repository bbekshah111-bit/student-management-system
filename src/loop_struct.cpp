#include<iostream>
#include<string>

using namespace std;

struct student
{
    string name;
    int age;
    float gpa;
    int id;
};

student students[5];


int main()
{
    for(int i = 0; i < 5; i++)
    {
        cout << "Enter Name: ";
        cin >> students[i].name;

        cout << "\n";

        cout << "Enter Age: ";
        cin >> students[i].age;

        cout << "\n";

        cout << "Enter GPA: ";
        cin >> students[i].gpa;

        cout << "\n";
        
        cout << "Enter ID: ";
        cin >> students[i].id;

        cout << "\n";

    }

    for(int i = 0; i < 5; i++)
    {
        cout << "Name: " << students[i].name << "\n";
        cout << "Age: " << students[i].age << "\n";
        cout << "GPA: " << students[i].gpa << "\n";
        cout << "ID: " << students[i].id << "\n";
    }
}