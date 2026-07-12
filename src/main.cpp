#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cctype>

using namespace std;

class Student
{
    private:
        string name;
        int age;
        float gpa;
        int id;


    public:
        Student(string StudentName, int StudentAge, float StudentGpa, int StudentId)
        {
            this->name = StudentName;
            this->age = StudentAge;
            this->gpa = StudentGpa;
            this->id = StudentId;
        }

        Student()
        {

        }

        string getName()
        {
            return name;
        }

        int getAge()
        {
            return age;
        }

        float getGpa()
        {
            return gpa;
        }

        int getId()
        {
            return id;
        }

        void setName(string newName)
        {
            name = newName;
        }

        void setAge(int newAge)
        {
            age = newAge;
        }

        void setGpa(float newGpa)
        {
            gpa = newGpa;
        }

        void setId(int newId)
        {
            id = newId;
        }

        void display()
        {
            cout << "1.Name: " << name <<"\n";
            cout << "2.Age: " << age << "\n";
            cout << "3.GPA: " << gpa << "\n";
            cout << "4.ID: " << id << "\n";
            cout << "\n\n";
    
        }
        

};


class StudentManager
{
    private:

        vector<Student> students;


    public:

        void loadStudentData();
        void saveStudentData();
        int findStudent(int idNo);
        void displayStudents();
        void searchStudent();
        void addStudents();
        void updateStudent();
        void searchByName();
        void deleteStudent();
        void executeChoice(int choice);
        void displayMenu();
        int getUserChoice();
        void run();
        

};


bool checkIsName(const string& input)
{

    if(input.empty())
    {
        return false;
    }

    bool hasLetter = false;

    for(char ch: input)
    {
        if(isalpha(ch))
        {
            hasLetter = true;
        }

        else if(ch == ' ')
        {
            continue;
        }

        else
        {
            return false;
        }
    }

    return hasLetter;

}


bool checkIsFloat(const string& input)
{
    if(input.empty())
    {
        return false;
    }

    bool hasDigit = false;
    int dotCount = 0;

    for(char ch: input)
    {
        if(isdigit(ch))
        {
            hasDigit = true;
        }

        else if(ch == '.')
        {
            dotCount++ ;
        }

        else
        {
            return false;
        }
    }

    return dotCount <=1 && hasDigit;

}


bool checkIsDigit(const string& input)
{
    if(input.empty())
    {
        return false;
    }

    for(char ch: input)
    {
        if(!isdigit(ch))
        {
            return false;     
        }
    }

    return true;
    
}


string validateNameInput(const string& message)
{
    string name;


    while(true)
    {
        cout << message;
        getline(cin, name);

        if(checkIsName(name))
        {
            return name;
        }

        else
        {
            cout << "Invalid!, please enter a valid name: \n";
        }

    }
}


int validateUserInput(const string& message, int minValue, int maxValue )
{
    string variable;

    while(true)
    {

        cout << message;
        getline(cin, variable);
        
        if(checkIsDigit(variable))
        {
            int to_int = stoi(variable);
            if( to_int >= minValue && to_int <= maxValue)
            {
                return to_int;
            }

            else
            {
                cout<< "Invalid range, please enter between " << minValue << " - " << maxValue << "\n";
            }
        }

        else
        {
            cout << "Invalid input please enter an integer.\n";

        }
    }
}


float validateFloatInput(const string& message, float minValue, float maxValue)
{

    string variable;

    while(true)
{
    cout << message;
    getline(cin, variable);

    if(checkIsFloat(variable))
    {
        float to_float = stof(variable);
        
        if(to_float >= minValue && to_float <= maxValue)
        {
            return to_float;
        }

        else
        {
            cout<< "Invalid range, please enter between "<< minValue << " - " << maxValue << "\n";
        }
    }

    else
    {
        cout << "Invalid input, please enter again.\n";
    }

}

}


void StudentManager::loadStudentData()
{
    string name;
    int age;
    float gpa;
    int id;

    ifstream file("student.txt");

    if (!file)
    {
        return;
    }

    while(getline(file, name))
    {
        file >> age ;
        file >> gpa ;
        file >> id ;

        file.ignore();

        Student student(name, age, gpa, id);
        students.push_back(student);

    }

    file.close();
    
}


void StudentManager::saveStudentData()
{
    ofstream file("student.txt");

    for(int i=0; i<students.size(); i++)
    {
        file << students[i].getName() << "\n";
        file << students[i].getAge() << "\n";
        file << students[i].getGpa() << "\n";
        file << students[i].getId() << "\n";

    }

    file.close();
}

int StudentManager::findStudent(int idNo)
{
    for(int i=0; i<students.size(); i++)
    {
        if(students[i].getId() == idNo)
        {
            return i;
        }
        
    }

    return -1;
}


void StudentManager::displayStudents()
{
    if(students.size()==0)
    {
        cout << "No students found!\n";
        return;
    }


    for(int i = 0; i < students.size(); i++)
    {

        students[i].display();
       
    }
}

void StudentManager::searchStudent()
{
    int idNo;
    
    idNo = validateUserInput("Enter Student Id", 1, 10000);

    int index = findStudent(idNo);


    if(index >= 0)
    {

        //displayStudent(index);
        students[index].display();

    }
    

    else
    {
        cout << "Student with ID " 
        << idNo 
        << " was not found.\n " ;
    }

}


void StudentManager::addStudents()
{


    //cout << "Enter Name: ";
    string name = validateNameInput("Enter Name: ");
    //getline(cin, students[studentCount].name );

    cout << "\n";

    //cout << "Enter Age: ";
    int age = validateUserInput("Enter Age: ", 1, 150);
    //cin >> students[studentCount].age;

    cout << "\n";

    //cout << "Enter GPA: ";
    float gpa = validateFloatInput("Enter GPA: ", 0.0, 4.0);
    //cin >> students[studentCount].gpa;

    cout << "\n";
            
    //cout << "Enter ID: ";
    int ids;
   
    while(true)
    {
        ids = validateUserInput("Enter ID: ", 1, 10000);

        if(findStudent(ids) != -1)
        {
            cout << "Invalid! this ID already exists. Please enter other ID: \n\n";
        }

        else
        {
           break; 
        }
    }


    Student student( name, age, gpa, ids);
    students.push_back(student);

    //students[studentCount].id = validateUserInput("Enter ID: ", 1, 10000);
    //cin >> students[studentCount].id;


    cout << "\n";
    saveStudentData();

    cout << "Student added successfully!\n";


}


void StudentManager::updateStudent()
{
    int id;
    int position;

    //cout << "Enter the ID of student you whose information you want to edit: ";
    id = validateUserInput("Enter the ID of student whose information you want to edit: ", 1, 10000);
    //cin >> id;

    int index = findStudent(id);
     if (index >= 0)
     
     {
     
        students[index].display();

        cout << "*note : please choose the field you want to update.\n";
        //cout << "Select what you want to edit: ";
        position = validateUserInput("Select what you want to edit: ", 1, 4);
        //cin >> position;


        switch(position)
        {
        case 1:
            {string newName;
            //cout << "Enter new name: ";
            newName = validateNameInput("Enter New Name: ");
            //getline(cin, newName);
            students[index].setName(newName);
            saveStudentData();
            break;}

        case 2:
            {int newAge;
            //cout << "Enter new age: ";
            newAge = validateUserInput("Enter new age: ", 1, 150);
            //cin >> newAge;
            students[index].setAge(newAge);
            saveStudentData();
            break;}

        case 3:
            {float newGPA;
            //cout << "Enter new GPA: ";
            newGPA = validateFloatInput("Enter new GPA: ", 0.0, 4.0);
            //cin >> newGPA;
            students[index].setGpa(newGPA);
            saveStudentData();
            break;}

        case 4:
            {int newID;
            //cout << "Enter new ID: ";

            while(true)
            {
                newID = validateUserInput("Enter new ID: ", 1, 10000);

                if(findStudent(newID) == -1)
                {
    
                    students[index].setId(newID);
                    break;
                }

                else if(students[index].getId() == newID)
                {
                    students[index].setId(newID);
                    break;
                }

                else
                {
                    cout << "Sorry! this ID already exists please enter a new ID: \n";
                }
            }
            //cin >> newID;
            //students[index].id = newID;
            saveStudentData();
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


void StudentManager::searchByName()
{
    string name;
    bool found = false;

    //cout << "Enter the name of Student: ";
    name = validateNameInput("Enter the name of Student: ");
    //getline(cin, name);

    cout << "Students Found: \n";


    for(int i=0; i<students.size(); i++)
    {
        if(students[i].getName() == name)
        {
            students[i].display();
            found = true;
        }
    }

    if(found == false)
    {
        cout << "sorry! No student with this name found.";
    }

}


void StudentManager::deleteStudent()
{
    int deleteID;

    //cout << "Enter the ID of student you want to delete: ";
    deleteID = validateUserInput("Enter the ID of student you want to delete: ", 1, 10000);
    //cin >> deleteID;

    int index = findStudent(deleteID);

    if(index >= 0)
    {
        int opt;
        cout << "You want to delete this student: \n";
        students[index].display();
        cout << "\n\n";
        cout << "Please confirm: \n";
        cout << "1. Yes \n";
        cout << "2. No \n";
        //cout << "Enter your choice: ";
        opt = validateUserInput("Enter your choice: ", 1, 2);
        //cin >> opt;

        switch (opt)
        {
        case 1:
            students.erase(students.begin() + index);

            saveStudentData();
            cout << "Student deleted successfully.\n";
            break;

        case 2:
            break;
        
        default:
            cout << "Invalid! option, please choose correct one.";
            break;
        }
        

    }

    else
    {
        cout << "Student with this ID was not found.";
    }
}



void StudentManager::executeChoice(int choice)
{

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
            break;
        
        
        default:
            cout << "Invalid! option, please choose a valid one.";
            break;
        }


}

int StudentManager::getUserChoice()
{
     return validateUserInput("Enter your choice: ", 1, 7);
}

 void StudentManager::displayMenu()
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

}

void StudentManager::run()
{

    loadStudentData();
    bool isRunning = true;
    
    while(isRunning)
    {
        displayMenu();

        int choice = getUserChoice();

        executeChoice(choice);

        if(choice == 7)
        {
            isRunning = false;
        }

    }
}


int main()
{
    StudentManager manager;
    manager.run();
    return 0;
}
