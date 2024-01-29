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
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backTracking(nums, used);
        return result;
    }

private:
    vecContainer res;
    vector<vecContainer> result;

    void backTracking(vecContainer &nums, vector<bool> &used) {
        if (res.size() == nums.size()) {
            result.push_back(res);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if ((used[i] == true) || (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false))
                continue;
            res.push_back(nums[i]);
            used[i] = true;
            backTracking(nums, used);
            res.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    Solution s;

    return 0;
}