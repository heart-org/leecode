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
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() <= 1)
            return nums.size();
        int pre = 0;
        int cur = 0;
        int result = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            cur = nums[i + 1] - nums[i];
            if ((pre <= 0 && cur > 0) || (pre >= 0 && cur < 0)) {
                ++result;
                pre = cur;
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    return 0;
}