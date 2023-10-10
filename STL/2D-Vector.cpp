#include <iostream>
#include <vector>

using namespace std;

void test1() {
    vector<string> matrix{"Ali", "Ahmed", "Sara"};

    // String is 1D array of chars
    // What about vector of string?
    // Matrix of 3 rows, each one has dynamic columns
    // Ali
    // Ahmed
    // Sara

    cout << matrix.size() << "\n";      // 3 rows
    int rows = matrix.size();
    for (int i = 0; i < rows; ++i) {
        // Dynamic column sizes: 3 5 4
        cout << matrix[i].size() << " ";
    }
    cout << endl;
}

void print(vector<vector<int>> &v2d) {
    for (auto &row: v2d) { // auto = vector<int>
        for (auto &col: row) {    // auto = int
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

void test2() {
    // 2D Array using vector
    // (5,7) 2D array
    vector<int> row(5, 1); // 5 numbers, each is 1

    // 3 rows: each is 5 values of 1
    vector<vector<int>> v2d(3, row);

    print(v2d);

    int rows = v2d.size(), cols = v2d[0].size();    // 3, 5

    v2d[0][0] = 9;
    v2d[1].push_back(5);
    v2d[1].push_back(6);
    v2d[2].erase(v2d[2].begin());
    print(v2d);
}

void test3() {
    // 3D Array using vector
    // (5,7) 2d array with initial value 3
    vector<vector<vector<int>>> v3d(5, vector<vector<int>>(6, vector<int>(7,3)));

    // 5 x 6 x 7
    cout << v3d.size() << " " << v3d[0].size() << " " << v3d[0][0].size() << endl;

    for (int i = 0; i <v3d.size(); ++i) {
        print(v3d[i]);
    }
}

int main() {
    test1();
    test2();
    test3();

    return 0;
}