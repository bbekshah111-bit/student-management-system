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
            name = StudentName;
            age = StudentAge;
            gpa = StudentGpa;
            id = StudentId;
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


int main()
{

    StudentManager manager;

    manager.loadStudentData();
    manager.saveStudentData();
    //manager.findStudent();
    manager.displayStudents();
    manager.searchStudent();
    return 0;
}





