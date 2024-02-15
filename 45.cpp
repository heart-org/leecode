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
        for (int i = 0; i < nums.size(); ++i) {
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

//贪心
int jump(vector<int> &nums) {
    int step = 0;
    int cur_cover = 0;
    int next_cover = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
        next_cover = max(next_cover, i + nums[i]);//当前所能到达的最远距离
        if (i == cur_cover) {
            /*
            倒数第二个为当前最远距离时，需要再次++，才能到达最后一个元素。
            相反，如果到达倒数第二个元素还没有到达当前最远距离时，说明不需要再走一步就能够到达最远距离了。
            */
            step++;
            cur_cover = next_cover;
        }
    }
    return step;
}

int main() {
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    s.jump(nums);

    return 0;
}