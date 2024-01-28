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

using vecStringContainer = vector<string>;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int pointSum = 0;
        backTracking(s, 0, pointSum);
        return result;
    }

private:
    vecStringContainer result;

    void backTracking(string &s, int startIndex, int pointSum) {
        if (pointSum == 3) {
            if (isvalid(s, startIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); ++i) {
            if (isvalid(s, startIndex, i)) {
                s.insert(s.begin() + i + 1, '.');
                pointSum += 1;
                backTracking(s, i + 2, pointSum);
                s.erase(s.begin() + i + 1);
                pointSum -= 1;
            }
        }
        return;
    }

    bool isvalid(string &s, int startIndex, int end) {
        if (startIndex > end)
            return false;
        if (s[startIndex] == '0' && startIndex != end)
            return false;
        int num = 0;
        for (int i = startIndex; i <= end; ++i) {
            if (s[i] > '9' || s[i] < '0')
                return false;
            num = num * 10 + (s[i] - '0');
            if (num > 255)
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;

    return 0;
}