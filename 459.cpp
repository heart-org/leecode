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
    bool repeatedSubstringPattern(string s) {
        if (s.length() % 2 == 1)
            return false;
        int left = 0;
        int right = s.length() / 2;
        while (right < s.length()) {
            if (s[left++] != s[right++])
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;

    return 0;
}