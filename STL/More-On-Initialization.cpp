#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string input_str = "I am mostufa\nYou instructor for this course";

    for (auto [iss, line] = pair(istringstream (input_str), string{}); getline(iss, line);)
        cout << line << endl;

    return 0;
}

/*
 I am mostufa
You instructor for this course
 */