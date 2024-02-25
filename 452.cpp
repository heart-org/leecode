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
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.size() == 0)
            return 0;
        sort(points.begin(), points.end());
        int res = 1;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > points[i - 1][1])
                ++res;
            else
                points[i][1] = min(points[i][1], points[i - 1][1]);
        }
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}