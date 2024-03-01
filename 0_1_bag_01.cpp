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

int n = 6;
int bag_weight = 1;

class Solution {
    void solve() {
        vector<int> value{2, 3, 1, 5, 4, 3};
        vector<int> weight{2, 2, 3, 1, 5, 2};

        vector<vector<int>> dp(n, vector<int>(bag_weight + 1, 0));

        //第一行重量小于最大weight，则讲dps设置撑weight
        for (int i = weight[0]; i <= bag_weight; ++i) {
            dp[0][i] = value[0];
        }

        for (int i = 1; i < weight.size(); ++i) {
            for (int j = 0; j <= bag_weight; ++j) {
                if (j < weight[i])
                    dp[i][j] = dp[i - 1][j];
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
                }
            }
        }
        cout << dp[weight.size() - 1][bag_weight] << endl;

    }

};

int main() {
    Solution s;


    return 0;
}