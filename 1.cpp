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
    vector<int> twoSum(vector<int> &nums, int target) {
        multimap<int, int> map;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                res.emplace_back(iter->second);
                res.emplace_back(i);
                return res;
            }
            map.insert({nums[i], i});
        }
        return res;
    }
};

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            m.insert({nums[i], i});
        }
        int left = 0;
        int right = 0;
        auto l_it = m.begin();
        auto r_it = m.rbegin();
        while(true){
            left = l_it->first;
            right = r_it->first;
            if ((left + right) == target){
                res.push_back(l_it->second);
                res.push_back(r_it->second);
                return res;
            }
            if ((left + right) > target){
                r_it++;
            } else
                l_it++;
        }
    }
};
*/

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            m.insert(make_pair(nums[i], i));
        }
        bool flag = true;
        int left = 0;
        int right = 0;
        multimap<int, int>::iterator l_it = m.begin();
        multimap<int, int>::reverse_iterator r_it = m.rbegin();
        while(flag){
            left = l_it->first;
            right = r_it->first;
            if ((left + right) == target){
                res.push_back(l_it->second);
                res.push_back(r_it->second);
                flag = false;
            }
            if ((left + right) > target){
                r_it++;
            } else
                l_it++;
        }
        return res;
    }
};
*/

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int slow = 0;
        vector<int> res;
        int size = nums.size();
        while(slow < (size - 1)){
            for (int fast = slow + 1; fast < size; ++fast) {
                if (nums[slow] + nums[fast] == target){
                    res.emplace_back(slow);
                    res.emplace_back(fast);
                    return res;
                }
            }
            slow++;
        }
        return res;
    }
};
*/

int main(){
    vector<int> nums = {3, 3};
    int target = 6;
    Solution s;
    s.twoSum(nums, target);


    return 0;
}