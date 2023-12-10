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
    int maxProfit(vector<int> &prices) {
        int target = 1;
        int res = 0;
        stack<int> s;
        s.push(prices[0]);
        while (target < prices.size()) {
            if (s.empty())
                s.push(prices[target]);
            else {
                if (prices[target] < s.top()) {
                    s.pop();
                    s.push(prices[target]);
                } else {
                    if (target + 1 < prices.size()) {
                        if (prices[target] > prices[target + 1]) {
                            res += prices[target] - s.top();
                            s.pop();
                        }
                    } else
                        res += prices[target] - s.top();
                }
            }
            target++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    s.maxProfit(prices);

    return 0;
}