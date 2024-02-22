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
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                --k;
            }
        }
        if (k > 0) {
            sort(nums.begin(), nums.end());
            while (k > 0) {
                nums[0] *= -1;
                --k;
            }
        }
        int res = 0;
        for (auto i: nums) {
            res += i;
        }
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}