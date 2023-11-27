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
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int slow, fast;
        slow = fast = 1;
        while(fast < nums.size()){
            if (nums[fast] != nums[fast - 1]){
                nums[slow++] = nums[fast];
            }
            ++fast;
        }
        return slow;
    }
};

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution s;
    s.removeDuplicates(nums);

    return 0;
}