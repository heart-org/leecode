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
    int maxSubArray(vector<int> &nums) {
        int result = INT_MIN;
        int cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cur += nums[i];
            result = max(cur, result);
            if (cur < 0)
                cur = 0;
        }
        return result;
    }
};

int main() {
    Solution s;

    return 0;
}