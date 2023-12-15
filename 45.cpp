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
    int jump(vector<int> &nums) {
        if (nums.size() == 1)
            return 0;
        int cover = 0;
        int step = 0;
        int first_cover = 0;
        for (int i = 0; i <= cover; ++i) {
            cover = max(nums[i] + i, cover);
            if (i == first_cover) {
                step++;
                first_cover = cover;
            }
            if (first_cover >= nums.size() - 1)
                break;
        }
        return step;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    s.jump(nums);

    return 0;
}