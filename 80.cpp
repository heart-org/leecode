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
        int val, slow, fast;
        val = slow =0;
        fast = 2;
        while(fast < nums.size()){
            if (nums[slow] == nums[slow + 1]){
                if(nums[slow] == nums[fast]){
                    while(fast < nums.size() - 1){
                        if (nums[fast] == nums[fast + 1])
                            fast++;
                        else
                            break;
                    }
                    nums[val++] = nums[slow++];
                    nums[val++] = nums[fast++];
                    slow = fast;

                }else{
                    nums[val++] = nums[slow++];
                    nums[val++] = nums[slow++];
                }
                fast += 2;
            }else{
                nums[val++] = nums[slow++];
                fast++;
            }
        }
        if(slow < nums.size()){
            for (slow; slow < nums.size(); ++slow) {
                nums[val++] = nums[slow];
            }
        }
        return val;
    }
};

/*
//官方题解
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
 */
int main(){
    Solution s;
    vector<int> nums = {1,1,2,2,2,3};
    s.removeDuplicates(nums);


    return 0;
}