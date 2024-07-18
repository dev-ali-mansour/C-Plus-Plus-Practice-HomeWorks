#include <iostream>
#include <vector>

using namespace std;

class Chessboard {
private:
    int rows;
    int columns;
    vector<vector<int>> board;

    class Row {
    private:
        vector<int> &row;
    public:
        Row(vector<int> &row_) : row(row_) {}

        int &operator[](int col) {
            return row[col];
        }
    };

public:
    Chessboard(int rows_, int columns_) :
            rows(rows_), columns(columns_), board(rows_, vector<int>(columns_, 0)) {}

    int &operator()(int row, int col) {
        return board[row][col];
    }

    Row operator[](int row) {
        return Row(board[row]);
    }

};

int main() {
    Chessboard board(2, 3); // 2×3 Grid

    board(0, 0) = 10;
    board[0][1] = 20;

    cout << board[0][0] << " " << board(0, 1);

    return 0;
}