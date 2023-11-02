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
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<int> s;
        vector<vector<int>> ans;
        if (nums.size() == 0)
            return  ans;
        int left = 0;
        int right = 0;
        bool flag = true;
        sort(nums.begin(),nums.end());
        //[-4, -1, -1, 0, 1, 2]
        //[ 0,  1,  2, 3, 4, 5]
        // -4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3,  4,  4,  6,  6
        //  0,  1,  2,  3, 4, 5, 6, 7, 8, 9, 10,11, 12, 13, 14
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0)
                return ans;
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] + nums[i] > 0){
                    right--;
                }
                else if (nums[left] + nums[right] + nums[i] < 0) {
                        left++;
                }
                else {
                    s.push_back(nums[i]);
                    s.push_back(nums[left]);
                    s.push_back(nums[right]);
                    for (int n = 0; n < ans.size(); ++n) {
                        if (s[0] == ans[n][0] && s[1] == ans[n][1] && s[2] == ans[n][2])
                            flag = false;
                    }
                    if (flag)
                        ans.push_back(s);
                    s.clear();
                    flag = true;
                    right--;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums;
    Solution().threeSum(nums);

    return 0;
}