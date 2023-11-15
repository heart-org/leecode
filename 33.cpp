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
    int search(vector<int>& nums, int target) {
        if (!nums.size())
            return -1;
        if (nums.size() == 1)
            return target == nums[0] ? 0 : -1;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target){
                return mid;
            }
            if (nums[mid] < nums[right]){
                if (target > nums[mid] && target <= nums[right]  )
                    left = mid + 1;
                else
                    right = mid - 1;
            }else{
                if (target < nums[mid] && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {1, 3};
    int target = 2;
    Solution s;
    s.search(nums, target);

    return 0;
}