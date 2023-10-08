#include <iostream>

using namespace std;

template<typename T, int SIZE>
struct MyQueue {
    T arr[SIZE];
    int pos;

    MyQueue() {
        pos = 0;
    }

    void add_front(T elem) {
        arr[pos++] = elem;
    }

    template<typename Type>
    void sum_and_add(Type a, Type b) {
        arr[pos++] = a + b;
    }

    void print() {
        for (int i = 0; i < pos; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MyQueue<int, 12> q_dob;
    q_dob.add_front(3);
    q_dob.add_front(2);
    q_dob.sum_and_add<double>(2.5, 3.9);
    q_dob.print(); // 3 2 6

    return 0;
}