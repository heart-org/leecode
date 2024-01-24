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
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        int index = 0;
        backTracking(index, target, sum, candidates);
        return result;
    }

private:
    vector<vecContainer> result;
    vecContainer res;
    int sum = 0;

    void backTracking(int index, int target, int sum, vecContainer candidates) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.push_back(res);
            return;
        }
        for (int i = index; i < candidates.size(); ++i) {
            sum += candidates[i];
            res.push_back(candidates[i]);
            backTracking(i, target, sum, candidates);
            sum -= candidates[i];
            res.pop_back();
        }
        return;
    }
};

int main() {
    Solution s;
    vecContainer candidates{2, 3, 6, 7};
    int target = 7;
    s.combinationSum(candidates, target);

    return 0;
}