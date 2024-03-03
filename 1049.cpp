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
    int lastStoneWeightII(vector<int> &stones) {
        vector<int> dp(1501, 0);
        int sum = 0;
        for (int i = 0; i < stones.size(); ++i) {
            sum += stones[i];
        }
        int target = sum / 2;
        for (int i = 0; i < stones.size(); ++i) {
            for (int j = target; j >= stones[i]; --j) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        int res = sum - 2 * dp[target];
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}