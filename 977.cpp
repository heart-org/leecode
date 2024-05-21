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
    vector<int> sortedSquares(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
        return nums;
    }
};

int main() {
    Solution s;


    return 0;
}