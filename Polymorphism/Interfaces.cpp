class Printable {
public:
    virtual void print() const = 0;

    virtual ~Printable() {}
};

class Cloneable {
public:
    // Function to clone
    virtual ~Cloneable() {}
};

class Person : public Printable, public Cloneable {

};

class Employee : Person {

};
