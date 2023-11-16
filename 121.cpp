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
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int profit = 0;
        int min = 0;
        int fast = 1;
        while(fast < prices.size()){
            if (prices[fast] < prices[min])
                min = fast;
            else{
                profit = prices[fast] - prices[min];
                res = profit > res ? profit : res;
            }
            fast++;
        }
        return res;
    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    Solution s;
    s.maxProfit(prices);

    return 0;
}