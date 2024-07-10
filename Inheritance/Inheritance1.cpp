#include <iostream>

using namespace std;

class Person {
public:
    string name = "Ali";
    string email = "dev.ali.mansour@gmail.com";

    bool isValidEmailFormat() {
        return true;
    }
};

class Student : public Person {
private:
    double GPA;

public:
    void printGrades() {
        cout << name << " GPA = " << GPA;
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