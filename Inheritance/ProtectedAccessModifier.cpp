#include <iostream>
#include <vector>

using namespace std;

class Person {
protected:
    string name;
    string email;
    string address;
    string national_id;

public:
    bool isValidEmailFormat() { return true; }

    void setName(const string &name_) {
        name = name_;
    }
};

class Student : public Person {
private:
    int starting_study_year;
    double GPA;
    vector<int> studied_courses;

public:
    void addCourseGrade(int course_id, double grade) {}

    void printGrades() {
        cout << name << " GPA " << GPA << endl;
    }

    void setGPA(double gpa) {
        GPA = gpa;
    }
};

class Teacher : public Person {
private:
    int starting_employment_year;
    double current_salary;
    vector<int> teaching_courses;

public:
    void addCourse(int course_id) {}

    void setCurrentSalary(double currentSalary) {
        current_salary = currentSalary;
    }
};

int main() {
    Student student;
    student.setName("Morad");
    student.setGPA(3.5);
    student.printGrades();
//    student.name;   // Can't

    Teacher teacher;
    teacher.isValidEmailFormat();
    teacher.setCurrentSalary(5000.0);

    return 0;
}