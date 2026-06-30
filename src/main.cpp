#include<iostream>
#include<string>

using namespace std;

string student_names[5];
int student_count = 0;

void add_students()
{
    if (student_count>=5)
    {
        cout << "Sorry! the list is full, can't store more.";
    }


    else
    {
        cout<< "Enter Student's Name: ";
        cin >> student_names[student_count];
        cout << "\n";
        student_count++;
    }
    
}

void display_students()
{
    if(student_count==0)
    {
        cout << "No student founded!\n";
    }

    for(int i = 0; i<student_count; i++)
    {
        cout << student_names[i];
        cout << "\n";
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
