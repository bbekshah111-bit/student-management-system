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




void displayStudent( int index)
{
    cout << "Name: " << students[index].name <<"\n";
    cout << "Age: " << students[index].age << "\n";
    cout << "GPA: " << students[index].gpa << "\n";
    cout << "ID: " << students[index].id << "\n";
    cout << "\n\n";
    
}



void displayStudents()
{
    if(studentCount==0)
    {
        cout << "No student founded!\n";
        return;
    }


    for(int i = 0; i < studentCount; i++)
    {
        displayStudent(i);
    }
}


int findStudent(int idNo)
{
    for(int i=0; i<studentCount; i++)
    {
        if(students[i].id == idNo)
        {
            return i;
        }
        
    }

    return -1;
}


void searchStudent()
{
    int idNo;

    cout << "Enter Student ID: ";
    cin >> idNo;

    int index = findStudent(idNo);


    if( index >= 0)
    {
        cout << "Here is the student's information with the ID Number: " << idNo << "\n";

        displayStudent(index);

    }

    else if (index == -1)
    {
        cout << "Student with ID" 
        << idNo 
        << "was not found.\n " ;
    }


}

void searchByName()
{
    string name;
    bool found = false;

    cout << "Enter the name of Student: ";
    cin >> name;

    cout << "Students Found: \n";


    for(int i=0; i<studentCount; i++)
    {
        if(students[i].name == name)
        {
            displayStudent(i);

            found = true;
        }
    }

    if(found == false)
    {
        cout << "sorry! No student with this name found.";
    }

}



int main()
{

    bool shouldExit = false;
    int choice;
    
    do
    {
        cout << "---------------------------------------------\n";
        cout << "STUDENT MANAGEMENT SYSTEM\n";
        cout << "---------------------------------------------\n";
        cout << "\n\n";
        cout << "1. Add Student\n";
        cout << "2. Display Student\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "\n\n";
        cout << "Enter Choice: ";


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
            searchStudent();

        }

        else if(choice == 4)
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

