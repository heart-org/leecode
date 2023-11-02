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

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        //int count = board[0].size();
//        map<char, int> row_map;
//        map<char, int> col_map;
//        map<char, int> square_map;
        /*
        //判断每一行
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                if (board[i][j] != '.') {
                    row_map[board[i][j]]++;
                }
            }
            for (auto &k: row_map) {
                if (k.second != 1) {
                    return false;
                }
            }
            row_map.clear();

        }

        //判断每一列和每一行
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                if (board[i][j] != '.') {
                    row_map[board[i][j]]++;
                }
                if (board[j][i] != '.') {
                    col_map[board[j][i]]++;
                }
            }
            for (auto &k: col_map) {
                if (k.second != 1) {
                    return false;
                }
            }
            for (auto &k: row_map) {
                if (k.second != 1) {
                    return false;
                }
            }
            row_map.clear();
            col_map.clear();
        }
        //判断3✖3
        int row = 3;
        int col = 3;
        for (int i = 0; i < count; i += row) {
            for (int j = 0; j < count; j += col) {
                for (int k = i; k < i + row; k++) {
                    for (int s = j; s < j + col; s++) {
                        if (board[k][s] != '.')
                            square_map[board[k][s]]++;
                    }
                }
                for (auto &m: square_map) {
                    if (m.second != 1) {
                        return false;
                    }
                }
                square_map.clear();
            }
            */
        /*二
        int row = 3;
        int col = 3;
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                if (board[i][j] != '.') {
                    row_map[board[i][j]]++;
                }
                if (board[j][i] != '.') {
                    col_map[board[j][i]]++;
                }
                for (auto &k: col_map) {
                    if (k.second != 1) {
                        return false;
                    }
                }
                for (auto &k: row_map) {
                    if (k.second != 1) {
                        return false;
                    }
                }
                if ((i % 3 == 0) && (j % 3 == 0)) {
                    for (int m = i / 3 * 3; m < i + row; m++) {
                        for (int s = j / 3 * 3; s < j + col; s++) {
                            if (board[m][s] != '.')
                                square_map[board[m][s]]++;
                        }
                    }
                    for (auto &n: square_map) {
                        if (n.second != 1) {
                            return false;
                        }
                    }
                    square_map.clear();
                }
            }
            row_map.clear();
            col_map.clear();
        }
         */
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool block[9][9] = {false};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(board[i][j] != '.'){
                    int x = board[i][j] - '0' -1;
                    if(row[i][x] || col[j][x] || block[i / 3 * 3 + j / 3][x])
                        return false;
                    row[i][x] = true;
                    col[j][x] = true;
                    block[i / 3 * 3 + j / 3][x] = true;
                }

            }

        }
      return true;
    }
};

int main() {
    vector<vector<char>> x = {{'.', '.', '4', '.', '.', '.', '6', '3', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                              {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
                              {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
                              {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
                              {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    cout<<Solution().isValidSudoku(x);
    return 0;
}