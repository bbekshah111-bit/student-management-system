#include<iostream>
#include<fstream>
#include<vector>

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
        


};


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





