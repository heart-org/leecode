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

using vecContainer = vector<int>;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        result.push_back(res);
        if (nums.empty())
            return result;
        sort(nums.begin(), nums.end());
        backTracking(nums, 0);
        return result;
    }

private:
    vecContainer res;
    vector<vecContainer> result;

    void backTracking(vecContainer &nums, int startIndex) {
        for (int i = startIndex; i < nums.size(); ++i) {
            if (i > startIndex && nums[i] == nums[i - 1])
                continue;
            res.push_back(nums[i]);
            result.push_back(res);
            backTracking(nums, i + 1);
            res.pop_back();
        }
    }
};

int main() {
    Solution s;

    return 0;
}