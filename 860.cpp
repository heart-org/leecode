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
    bool lemonadeChange(vector<int> &bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for (int money: bills) {
            //每次判断当前金额能不能找零
            if (money == 5)
                ++five;
            if (money == 10) {
                if (five <= 0)
                    return false;
                ++ten;
                --five;
                ++twenty;
            }
            if (money == 20) {
                if (five > 0 && ten > 0) {
                    --five;
                    --ten;
                    ++twenty;
                } else if (five >= 3) {
                    five -= 3;
                } else
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;

    return 0;
}