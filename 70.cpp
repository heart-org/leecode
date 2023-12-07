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
    int climbStairs(int n) {
        if (n == 0)
            return 0;
        vector<int> dp(3);
        dp[0] = 1;
        dp[1] = 1;
        int res = 1;
        for (int i = 2; i <= n; ++i) {
            res = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = res;
        }
        return res;
    }
};

int main() {

    return 0;
}