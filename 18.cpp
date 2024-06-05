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

using vecContain = vector<int>;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vecContain> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0 && nums[i] > target)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0)
                    break;
                if (nums[j] == nums[j - 1] && j > i + 1)
                    continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if ((long) nums[left] + nums[j] + nums[right] + nums[i] > target)
                        right--;
                    else if ((long) nums[left] + nums[j] + nums[right] + nums[i] < target)
                        left++;
                    else {
                        res.emplace_back(vecContain{nums[i], nums[j], nums[left], nums[right]});
                        while (nums[right] == nums[right - 1] && right > left)
                            right--;
                        while (nums[left] == nums[left + 1] && left < right)
                            left++;
                        right--;
                        left++;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}