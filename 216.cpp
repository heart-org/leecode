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

using vecContainer = vector<int>;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        for (int i = 1; i < k; ++i) {
            sum += i;
        }
        if (sum > n)
            return res;
        int startIndex = 1;
        int sum = 0;
        backTracking(k, n, sum, startIndex);
        return res;
    }

private:
    vector<vecContainer> res;
    vecContainer vec;
    int sum = 0;

    void backTracking(int k, int targetSum, int sum, int startIndex) {
        if (vec.size() == k) {
            if (sum == targetSum)
                res.push_back(vec);
            return;
        }
        //剪枝
        for (int i = startIndex; i <= 9 - (k - vec.size()) + 1; ++i) {
            sum += i;
            if (sum > targetSum) {
                sum -= i;
                return;
            }
            vec.push_back(i);
            backTracking(k, targetSum, sum, i + 1);
            sum -= i;
            vec.pop_back();
        }
    }
};

int main() {
    Solution s;

    return 0;
}