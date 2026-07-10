#include<iostream>
#include<vector>

using namespace std;

class Student
{
    private:
        string Name;
        int Age;
        float Gpa;
        int Id;


    public:
        Student(string StudentName, int StudentAge, float StudentGpa, int StudentId)
        {
            Name = StudentName;
            Age = StudentAge;
            Gpa = StudentGpa;
            Id = StudentId;
        }

        string getName()
        {
            return Name;
        }

        int getAge()
        {
            return Age;
        }

        float getGpa()
        {
            return Gpa;
        }

        int getId()
        {
            return Id;
        }

        void display()
        {
            cout << "1.Name: " << Name <<"\n";
            cout << "2.Age: " << Age << "\n";
            cout << "3.GPA: " << Gpa << "\n";
            cout << "4.ID: " << Id << "\n";
            cout << "\n\n";
    
        }

};


class StudentManager
{
    private:

        vector<Student> students;


    public:

        StudentManager()
        {
            
        }

        void addStudent(students.push_back(Student(string name, int age, float gpa, int id)))
        {


        }
};





