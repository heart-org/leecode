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

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int row = obstacleGrid.size();
        int list = obstacleGrid[0].size();
        if (obstacleGrid[row - 1][list - 1] == 1 || obstacleGrid[0][0] == 1)
            return 0;

        vector<vector<int>> dp(row, vector<int>(list, 0));
        for (int i = 0; i < row && obstacleGrid[i][0] == 0; ++i) {//遇到障碍就停止dp初始化，因为后面的位置到达不了，只能向下或向右
            dp[i][0] = 1;
        }

        for (int i = 0; i < list && obstacleGrid[0][i] == 0; ++i) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < list; ++j) {
                if (obstacleGrid[i][j] == 1)
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[row - 1][list - 1];
    }
};

int main() {
    Solution s;


    return 0;
}