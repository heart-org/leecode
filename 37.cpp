#include "iostream"
#include "queue"
#include "stack"
#include "vector"
#include "algorithm"
#include "cstring"
#include "cmath"
#include "set"
#include "map"
#include "numeric"
#include "unordered_set"
#include "unordered_map"
#include "array"
#include "cctype"
#include "list"

using namespace std;

using vecCharContainer = vector<char>;

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        backTracking(board);
    }

private:
    bool backTracking(vector<vecCharContainer> &board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; ++k) {
                        if (isValid(i, j, k, board)) {
                            board[i][j] = k;
                            if (backTracking(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(int row, int col, char k, vector<vecCharContainer> &board) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == k)
                return false;
        }
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == k)
                return false;
        }
        int sub_row = (row / 3) * 3;
        int sub_col = (col / 3) * 3;
        for (int i = sub_row; i < sub_row + 3; ++i) {
            for (int j = sub_col; j < sub_col + 3; ++j) {
                if (board[i][j] == k)
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;

    return 0;
}