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

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int> &nums) {
        vector<int> ans(nums.size() * 2);
        for (int i = 0; i < nums.size(); ++i) {
            ans[i + nums.size()] = ans[i] = nums[i];
        }
        return ans;
        //方法2
        nums.insert(nums.end(), nums.begin(), nums.end());
        return nums;
    }
};

int main() {
    vector<int> nums = {1,2,1};
    Solution().getConcatenation(nums);

    return 0;
}