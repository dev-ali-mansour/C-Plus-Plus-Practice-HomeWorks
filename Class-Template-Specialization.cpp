#include <iostream>

using namespace std;

template<class T>
struct Game {
};

template<>
struct Game<string> {

};

int main() {
    Game<int> a;
    Game<string> b;
    return 0;
}