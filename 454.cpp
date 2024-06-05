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
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        unordered_map<int, int> map;
        //统计nums1和nums2不同元素的组合值
        for (int a: nums1) {
            for (int b: nums2) {
                map[a + b]++;
            }
        }
        int count = 0;//nums1、2、3、4等于0的次数
        for (int c: nums3) {
            for (int d: nums4) {
                if (map.find(0 - (c + d)) != map.end()) {
                    count += map[0 - (c + d)];//count加上当前sum为0的情况，ab中可能不止一个所以加上map索引
                }
            }
        }
        return count;
    }
};


int main() {
    Solution s;

    return 0;
}