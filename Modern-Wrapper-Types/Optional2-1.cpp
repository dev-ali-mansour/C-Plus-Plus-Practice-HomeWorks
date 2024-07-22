#include <iostream>
#include <vector>
#include <optional>
using namespace std;

// https://cpluspluspedia.com/en/tutorial/2423/std--optional

struct Animal {
    string name;
};

struct Person {
    string name;
    optional<Animal> pet;
};

int main() {
    Person person;
    person.name = "John";

    if (person.pet) {
        cout << person.name << "'s pet's name is " <<
            person.pet->name << endl;
    }
    else {
        cout << person.name << " is alone." << endl;
    }
}
