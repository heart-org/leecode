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
    int longestConsecutive(vector<int> &nums) {
        if (nums.size() == 1)
            return 1;
        else {
            sort(nums.begin(), nums.end());
            int count = 1;
            int ans = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if ((i + 1) == nums.size()) {
                    if (count > ans) {
                        ans = count;
                    }
                    continue;
                }
                if (nums[i] == nums[i + 1] - 1) {
                    count++;
                    continue;
                }
                if (nums[i] == nums[i + 1]){
                    continue;
                }
                if (count >= ans) {
                    ans = count;
                }
                count = 1;
            }
            return ans;
        }

    }
};


int main() {
    vector<int> nums = {7,-9,3,-6,3,5,3,6,-2,-5,8,6,-4,-6,-4,-4,5,-9,2,7,0,0};
    Solution().longestConsecutive(nums);

    return 0;
}