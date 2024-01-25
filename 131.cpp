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
    vector<vector<string>> partition(string s) {
        backTracking(s, 0);
        return result;
    }

private:
    vector<vecStringContainer> result;
    vecStringContainer res;

    void backTracking(string s, int startIndex) {
        if (startIndex >= s.length()) {
            result.push_back(res);
            return;
        }
        for (int i = startIndex; i < s.size(); ++i) {
            if (isHuiWen(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);
                res.push_back(str);
            } else
                continue;
            backTracking(s, i + 1);
            res.pop_back();
        }
        return;
    }

    bool isHuiWen(string &s, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;

    return 0;
}