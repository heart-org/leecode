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
    int candy(vector<int> &ratings) {
        vector<int> res_left(ratings.size(), 1);
        vector<int> res_right(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1])
                res_left[i] = res_left[i - 1] + 1;
        }
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1])
                res_right[i] = res_right[i + 1] + 1;
        }
        int sum = 0;
        for (int i = 0; i < res_left.size(); ++i) {
            sum += (res_left[i] > res_right[i] ? res_left[i] : res_right[i]);
        }
        return sum;
    }
};

int main() {
    Solution s;

    return 0;
}