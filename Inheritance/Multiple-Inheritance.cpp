#include <iostream>
#include <vector>

using namespace std;

class Student {
protected:
    double gpa;
};

class Employee {
protected:
    double salary;
};

class TeachingAssistant : public Student, public Employee {
private:
    vector<int> courses_ids;

    void func() {
        gpa = 3.5;
        salary = 5000.0;
    };
};

int main() {
    TeachingAssistant assistant;

    return 0;
}