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
    int minCostClimbingStairs(vector<int> &cost) {
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            dp[i] = min((dp[i - 2] + cost[i - 2]), (dp[i - 1] + cost[i - 1]));
            cout << "dp[" << i << "] = " << dp[i] << endl;
        }
        cout << "result = " << dp.back() << endl;
        return dp.back();
    }
};

int main() {
    Solution s;
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    s.minCostClimbingStairs(cost);

    return 0;
}