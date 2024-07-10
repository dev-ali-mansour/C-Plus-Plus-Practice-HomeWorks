#include <iostream>

using namespace std;

class Person {
private:
    string name = "Ali";
    string email = "dev.ali.mansour@gmail.com";

public:
    bool isValidEmailFormat() {
        return true;
    }
};

class Student : public Person {
private:
    double GPA;

public:
    void printGrades() {
        // Now You can not see name as it is private!
//        cout << name << " GPA = " << GPA<<endl;
    }

    void setGPA(double gpa) {
        GPA = gpa;
    }
};

int main() {
    Student student;

    // Student is a Person
    student.setGPA(3.5);
    student.isValidEmailFormat();
    student.printGrades();

    // Person is not necessarily a student
    Person person;
    person.isValidEmailFormat();
    //person.printGrades(); // Nothing about student!

    return 0;
}