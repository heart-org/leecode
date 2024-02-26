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

using vec_type = vector<int>;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.size() == 0)
            return intervals;
        sort(intervals.begin(), intervals.end(), [](const vec_type &a, const vec_type &b) { return a[0] < b[0]; });
        vec_type res = intervals[0];
        vector<vec_type> result;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= res[1]) {
                res[1] = max(intervals[i][1], res[1]);
            } else {
                result.push_back(res);
                res = intervals[i];
            }
        }
        if (!res.empty())
            result.push_back(res);
        return result;
    }
};

int main() {
    Solution s;

    return 0;
}