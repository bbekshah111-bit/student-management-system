#include<iostream>
#include<string>

using namespace std;

struct Student
{
    string name;
    int age;
    float gpa;
    int id;
};

const int MAX_STUDENT = 5;

Student students[MAX_STUDENT];

int studentCount = 0;

void addStudents()
{
    if (studentCount>=MAX_STUDENT)
    {
        cout << "Sorry! the list is full, can't store more.";

        return;
    }



    else
    {
        cout << "Enter Name: ";
        cin >> students[studentCount].name;

        cout << "\n";

        cout << "Enter Age: ";
        cin >> students[studentCount].age;

        cout << "\n";

        cout << "Enter GPA: ";
        cin >> students[studentCount].gpa;

        cout << "\n";
            
        cout << "Enter ID: ";
        cin >> students[studentCount].id;

        studentCount++;

        cout << "\n";


    }
}

void displayStudents()
{
    if(studentCount==0)
    {
        cout << "No student founded!\n";
    }


    for(int i = 0; i < studentCount; i++)
    {
        cout << "Name: " << students[i].name << "\n";
        cout << "Age: " << students[i].age << "\n";
        cout << "GPA: " << students[i].gpa << "\n";
        cout << "ID: " << students[i].id << "\n";
    }
}

int main()
{

    bool shouldExit = false;
    int choice;
    
    do
    {
        cout << "\n";
        cout << "1. Add Student\n";
        cout << "2. Display Student\n";
        cout << "3. Exit\n\n";

        cin >> choice;

        if(choice == 1)
        {
            addStudents();
        }

        else if(choice == 2)
        {
            displayStudents();
        }

        else if(choice == 3)
        {
            cout << "Thankyou for the visit.";
            shouldExit = true;
        
        }

        else
        {
            cout << "Invalid! Choice.";
        }
        
    } while (shouldExit == false);
    
    return 0;
    
}
