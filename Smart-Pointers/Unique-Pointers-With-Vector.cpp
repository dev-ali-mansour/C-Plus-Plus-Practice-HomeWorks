#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void test() {
    vector<unique_ptr<int>> vec;

    vec.push_back(make_unique<int>(7));

    auto p1 = make_unique<int>(20);
    //vec.push_back(p1); CE: Copy constructor
    vec.push_back(std::move(p1));   // OK p1 now empty

    auto p2 = make_unique<int>(20);

    // emplace_back constructs in-place even without std::move
    vec.emplace_back(std::move(p2));
    vec.emplace_back(make_unique<int>(7));

    // Since C++17: You can use emplace_back with & return
    auto &b = vec.emplace_back(make_unique<int>(7));

    for (auto &p: vec) {   // You must use &
    }

}

int main() {

    return 0;
}