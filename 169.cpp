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
    int majorityElement(vector<int> &nums) {
        map<int, int> sort_map;
        for (auto i: nums) {
            sort_map[i]++;
        }
        int res = 0;
        int max = 0;
        for (auto i: sort_map) {
            if (max < i.second) {
                res = i.first;
                max = i.second;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 3};
    s.majorityElement(nums);

    return 0;
}