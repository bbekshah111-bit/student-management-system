#include<iostream>
#include<string>

using namespace std;


    struct student
    {
        int id;
        string name;
        float gpa;
        int age;
    };



    

int main()
{


    student s1;
    {
        cout << "Enter Name: ";
        cin >> s1.name;

        cout << "\n";

        cout << "Enter Age: ";
        cin >> s1.age; 

        cout << "\n";

        cout << "Enter GPA: ";
        cin >> s1.gpa;

        cout << "\n";

        cout << "Enter ID: ";
        cin >> s1.id;

        cout << "\n";


        cout << "Name: " << s1.name << "\n";
        cout << "Age: " << s1.age << "\n";
        cout << "GPA: " << s1.gpa << "\n";
        cout << "ID: " << s1.id << "\n";
    }
    

}