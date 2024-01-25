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
using boolVecContainer = vector<bool>;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        if (candidates.size() == 0)
            return result;
        int startIndex = 0;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        backTracking(startIndex, target, sum, candidates);
        return result;
    }

private:
    vecContainer res;
    vector<vecContainer> result;

    void backTracking(int startIndex, int target, int sum, vecContainer &candidates) {
        if (sum == target) {
            result.push_back(res);
            return;
        }
        for (int i = startIndex; i < candidates.size() && (sum + candidates[i] <= target); ++i) {
            if (i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }
            sum += candidates[i];
            res.push_back(candidates[i]);
            backTracking(i + 1, target, sum, candidates);
            sum -= candidates[i];
            res.pop_back();
        }
    }
};

int main() {
    Solution s;
    vecContainer candidates{2, 5, 2, 1, 2};
    int target = 5;
    s.combinationSum2(candidates, target);

    return 0;
}