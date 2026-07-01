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

Student students[5];

int student_count = 0;

void add_students()
{
    if (student_count>=5)
    {
        cout << "Sorry! the list is full, can't store more.";

        return;
    }



    else
    {
        cout << "Enter Name: ";
        cin >> students[student_count].name;

        cout << "\n";

        cout << "Enter Age: ";
        cin >> students[student_count].age;

        cout << "\n";

        cout << "Enter GPA: ";
        cin >> students[student_count].gpa;

        cout << "\n";
            
        cout << "Enter ID: ";
        cin >> students[student_count].id;

        student_count++;

        cout << "\n";


    }
}

void display_students()
{
    if(student_count==0)
    {
        cout << "No student founded!\n";
    }


    for(int i = 0; i < student_count; i++)
    {
        cout << "Name: " << students[i].name << "\n";
        cout << "Age: " << students[i].age << "\n";
        cout << "GPA: " << students[i].gpa << "\n";
        cout << "ID: " << students[i].id << "\n";
    }
}

int main()
{

    bool shouldstop = false;
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
            add_students();
        }

        else if(choice == 2)
        {
            display_students();
        }

        else if(choice == 3)
        {
            cout << "Thankyou for the visit.";
            shouldstop = true;
        
        }

        else
        {
            cout << "Invalid! Choice.";
        }
        
    } while (shouldstop == false);
    
    return 0;
    
}
