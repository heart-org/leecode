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
    int minSubArrayLen(int target, vector<int> &nums) {
        int res = INT_MAX;
        int sum = 0;
        int left = 0;
        int sublength = 0;
        for (int j = 0; j < nums.size(); ++j) {
            sum += nums[j];
            while (sum >= target) {
                sublength = j - left + 1;
                res = min(res, sublength);
                sum -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    s.minSubArrayLen(7, nums);

    return 0;
}