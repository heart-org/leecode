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
    bool canJump(vector<int> &nums) {
        if (nums.size() == 1)
            return true;
        int cover = 0;
        for (int i = 0; i <= cover; ++i) {
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1)
                return true;
        }
        return false;
    }
};

int main() {
    Solution s;

    return 0;
}