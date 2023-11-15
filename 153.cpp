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
    int findMin(vector<int>& nums) {
        /*
        int tag = 0;
        while(nums[tag] > nums[nums.size() - 1]){
            tag++;
        }
        return nums[tag];
         */
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = (right - left) / 2 + left;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};

int main(){




    return 0;
}