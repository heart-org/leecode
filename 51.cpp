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

using vecStrContainer = vector<string>;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vecStrContainer chessboard(n, string(n, '.'));
        backTracking(chessboard, n, 0);
        return result;
    }

private:
    vector<vecStrContainer> result;

    void backTracking(vecStrContainer &chessboard, int n, int row) {
        if (row == n) {
            result.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (isValid(chessboard, row, col, n)) {
                chessboard[row][col] = 'Q';
                backTracking(chessboard, n, row + 1);
                chessboard[row][col] = '.';
            }
        }
    }

    //每次选择当前row的一个位置进行插入来判断，所以不需要判断当前行是否有重复的元素
    bool isValid(vecStrContainer &chessboard, int row, int col, int n) {
        //检查列
        for (int i = 0; i < row; ++i) {
            if (chessboard[i][col] == 'Q')
                return false;
        }
        //检查左斜(45度角)
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        //检查右斜(135度角)
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;

    return 0;
}