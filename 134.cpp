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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int cur_sum = 0;
        int total_sum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total_sum += (gas[i] - cost[i]);
            cur_sum += (gas[i] - cost[i]);
            if (cur_sum < 0) {
                start = i + 1;
                cur_sum = 0;
            }
        }
        if (total_sum < 0)
            return -1;
        return start;
    }
};

int main() {
    Solution s;

    return 0;
}