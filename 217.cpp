#include<iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;

    }
};

int main(){
    vector<int> mylist = {1, 2, 3, 3, 5, 6};
    Solution().containsDuplicate(mylist);

    return 0;
}