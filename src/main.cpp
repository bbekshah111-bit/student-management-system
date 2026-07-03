#include<iostream>
#include<fstream>
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
    cout << "1.Name: " << students[index].name <<"\n";
    cout << "2.Age: " << students[index].age << "\n";
    cout << "3.GPA: " << students[index].gpa << "\n";
    cout << "4.ID: " << students[index].id << "\n";
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


    if(index >= 0)
    {

        displayStudent(index);

    }
    

    else
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




void updateStudent()
{
    int id;
    int position;

    cout << "Enter the ID of student you whose information you want to edit: ";
    cin >> id;

    int index = findStudent(id);
     if (index >= 0)
     
     {
     
        displayStudent(index);

        cout << "*note : please choose the field you want to update.\n";
        cout << "Select what you want to edit: ";
        cin >> position;


        switch(position)
        {
        case 1:
            {string newName;
            cout << "Enter new name: ";
            cin >> newName;
            students[index].name = newName;
            break;}

        case 2:
            {int newAge;
            cout << "Enter new age: ";
            cin >> newAge;
            students[index].age = newAge;
            break;}

        case 3:
            {float newGPA;
            cout << "Enter new GPA: ";
            cin >> newGPA;
            students[index].gpa = newGPA;
            break;}

        case 4:
            {int newID;
            cout << "Enter new ID: ";
            cin >> newID;
            students[index].id = newID;
            break;}

        
        default:
            cout << "Not a valid option. Please write the index of the given list. Example: 1 for name, 2 for age, ....";
            break;
        }


    }

    else 
    {
        cout<< "Student with this ID was not found.\n";
    }

    
}

void deleteStudent()
{
    int deleteID;

    cout << "Enter the ID of student you want to delete: ";
    cin >> deleteID;

    int index = findStudent(deleteID);

    if(index >= 0)
    {
        int opt;
        cout << "You want to delete this student: \n";
        displayStudent(index);
        cout << "\n\n";
        cout << "Please confirm: \n";
        cout << "1. Yes \n";
        cout << "2. No \n";
        cout << "Enter your choice: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            for(int i=index; i < studentCount - 1 ; i++)
            {
                students[i] = students[i + 1];
            }
            studentCount--;
            break;

        case 2:
            return;
        
        default:
            cout << "Invalid! option, please choose correct one.";
            break;
        }
        



    }

    else
    {
        cout << "Student with is ID was not found.";
    }
}


void loadStudentData()
{
    ifstream file("student.txt");

    while(studentCount < MAX_STUDENT && file >> students[studentCount].name)
    {
        file >> students[studentCount].age ;
        file >> students[studentCount].gpa ;
        file >> students[studentCount].id ;


        studentCount ++;
    }

    file.close();
}


int main()
{

    bool shouldExit = false;
    int choice;
    
    do
    {
        cout << "\n---------------------------------------------\n";
        cout << "STUDENT MANAGEMENT SYSTEM\n";
        cout << "---------------------------------------------\n";
        cout << "\n\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search by ID Student\n";
        cout << "4. Search Student by Name\n";
        cout << "5. Update Student Information\n";
        cout << "6. Delete Students\n";
        cout << "7. Exit\n";
        cout << "\n\n";
        cout << "Enter Choice: ";


        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudents();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;
        
        case 4:
            searchByName();
            break;

        case 5:
            updateStudent();
            break;

        case 6:
            deleteStudent();
            break;

        case 7:
            cout << "Thankyou for visiting.";
            shouldExit = true;
            break;
        
        
        default:
            cout << "Invalid! option, please choose a valid one.";
            break;
        }
        
    } while (shouldExit == false);
    
    return 0;
    
}

