//
// Created by org15 on 2023/6/17.
//
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
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>array(nums.size(), 1);
        int x = 1;
        for(int i = 1; i < nums.size(); i++){
            array[i] = nums[i - 1] * array[i - 1];
        }
        for (int j = (nums.size() - 1); j >= 0; j--) {
            array[j] *= x;
            x *= nums[j];
        }
        return array;
    }
};

int main(){
    Solution S;
    vector<int> nums = {1,2,3,4};
    S.productExceptSelf(nums);

    return 0;
}