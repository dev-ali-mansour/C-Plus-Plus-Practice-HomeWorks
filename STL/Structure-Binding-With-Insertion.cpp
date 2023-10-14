#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> st{4, 20, 30, 30, 20};

    // Can't take a reference for a return by value
    auto [iter1, is_inserted1] = st.insert(21); // true
    auto [iter2, is_inserted2] = st.insert(30); // false

    if (auto [iter3, success] = st.insert(15);success) {
        // here if inserted and we have an iterator
    }

}