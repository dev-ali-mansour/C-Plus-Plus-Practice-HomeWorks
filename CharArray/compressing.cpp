#include <iostream>

using namespace std;

int main() {
    string input;
    cin >> input;

    input += "$"; // a small trick to avoid special handling for the last group

    int group_sz = 1; // For first letter
    bool is_first_group = true;

    for (int i = 1; i < (int) input.size(); ++i) { // Start from 1
        if (input[i] != input[i - 1]) { // New group
            if (!is_first_group)cout << "_"; // Split from previous group
            cout << input[i - 1] << group_sz;
            group_sz = 0;
            is_first_group = false;
        }
        ++group_sz;
    }

    return 0;
}