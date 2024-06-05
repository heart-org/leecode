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
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> set1;
        unordered_set<int> set2(nums1.begin(), nums1.end());
        for (auto i: nums2) {
            if (set2.find(i) != set2.end())
                set1.insert(i);
        }
        vector<int> res{set1.begin(), set1.end()};
        //unorderedset转换成vector
        //vec = {set.begin(), set.end()};
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}