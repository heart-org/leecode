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

using strContainer = vector<string>;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
            return result;
        backTracking(0, digits);
        return result;
    }

private:
    const string letterMap[10] = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
    };
    strContainer result;
    string s;

    void backTracking(int index, string digits) {
        if (index == digits.length()) {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letter = letterMap[digit];
        for (int i = 0; i < letter.size(); ++i) {
            s.push_back(letter[i]);
            backTracking(index + 1, digits);
            s.pop_back();
        }
        return;
    }
};

int main() {
    Solution s;

    return 0;
}