#include <iostream>

using namespace std;

int main() {
    char arr[] = "hello";
    char *str = arr;

    while (*str != '\0')
        cout << *str++ << " ";  // h e l l o

    return 0;
}