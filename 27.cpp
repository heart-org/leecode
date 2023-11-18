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
    int removeElement(vector<int>& nums, int val) {
        int fast,slow = 0;
        for (fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != val)
                nums[slow++] = nums[fast];
        }
        return slow;
    }
};

/*
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};
*/

int main(){

    return 0;
}