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
private:
    class MyQueue {
    public:
        deque<int> que;

        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }

        void push(int value) {
            while (!que.empty() && que.back() < value) {
                que.pop_back();
            }
            que.push_back(value);
        }

        int get_max_value() {
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        MyQueue que;
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            que.push(nums[i]);
        }
        res.push_back(que.get_max_value());
        for (int i = k; i < nums.size(); ++i) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.push_back(que.get_max_value());
        }
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}