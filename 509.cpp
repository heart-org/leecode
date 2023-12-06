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

/*
class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
 */
class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        vector<int> dp(3);
        dp[0] = 0;
        dp[1] = 1;
        int res = dp[0] + dp[1];
        for (int i = 2; i <= n; ++i) {
            res = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = res;

        }
        return res;
    }
};


int main(){


    return 0;
}