#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int middle;
        while(left < right){
            middle = left + (right - left) / 2;
            if (nums[middle] > target)
                right = middle;
            else if (nums[middle] < target)
                left = middle + 1;
            else
                return middle;
        }
        return -1;

    }
};

class Search {
public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int cur;
        while (left <= right) {
            cur = left + (right - left) / 2;
            if (target > nums[cur])
                left = cur + 1;
            else if (target < nums[cur])
                right = cur - 1;
            else
                return cur;
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    Solution s;
    s.search(nums, target);

    return 0;
}
