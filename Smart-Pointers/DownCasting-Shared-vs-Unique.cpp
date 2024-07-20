#include <iostream>
#include <memory>

using namespace std;

class Person {
public:
    virtual ~Person() {}
};

class Employee : public Person {
};

int main() {
    shared_ptr<Person> base = make_shared<Employee>();

    shared_ptr<Employee> child1 = dynamic_pointer_cast<Employee>(base);

    if (child1)
        cout << base.use_count() << " " << child1.use_count() << endl;      // 2 2
    // Also see static_pointer_cast

    // No casting for unique, You have to do it with normal way
    unique_ptr<Person> baseu = make_unique<Person>();
    Employee *child2 = dynamic_cast<Employee *>(baseu.get());
    // DON'T do with shared ptr. as reference counter doesn't increase

    return 0;
}