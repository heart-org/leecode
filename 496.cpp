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

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> res1(nums1.size(), 0);
        vector<int> res2(nums2.size(), -1);
        s.push(0);
        for (int j = 1; j < nums2.size(); ++j) {
            while(!s.empty() && nums2[s.top()] < nums2[j]){
                res2[s.top()] = nums2[j];
                s.pop();
            }
            s.push(j);
        }
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]){
                    res1[i] = res2[j];
                }
            }
        }
        return res1;
    }
};

int main(){

    return 0;
}