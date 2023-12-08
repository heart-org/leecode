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

/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int flag = k % nums.size();
        vector<int> nums1(nums.size() - flag);
        vector<int> nums2(flag);
        for (int i = 0; i < nums1.size(); ++i) {
            nums1[i] = nums[i];
        }
        for (int i = 0; i < flag; ++i) {
            nums2[i] = nums[i + nums1.size()];
        }
        nums2.insert(nums2.end(), nums1.begin(), nums1.end());
        nums.assign(nums2.begin(), nums2.end());
    }
};
*/

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int flag = k % nums.size();
        int length = nums.size() - flag;
        vector<int> nums1(flag);
        for (int i = 0; i < flag; ++i) {
            nums1[i] = nums[i + length];
        }
        nums.erase(nums.end() - flag, nums.end());
        nums.insert(nums.begin(), nums1.begin(), nums1.end());
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(nums, 3);

    return 0;
}