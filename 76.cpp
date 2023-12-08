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

bool judge(vector<int> vec1, vector<int> vec2) {
    for (int i = 0; i < vec1.size(); ++i) {
        if (vec2[i] > vec1[i])
            return false;
    }
    return true;
}

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> vec1(58);
        vector<int> vec2(58);
        for (int i = 0; i < t.length(); ++i) {
            vec1[s[i] - 'A']++;
            vec2[t[i] - 'A']++;
        }
        int slow, fast, start;
        slow = start = 0;
        fast = t.length();
        int min_num = INT_MAX;
        while (fast < s.length()) {
            if (!judge(vec1, vec2)) {

            } else {
                vec1[s[slow++] - 'A']--;
                while (judge(vec1, vec2)) {
                    if (min_num < (fast - slow)) {
                        min_num = fast - slow;
                        start = slow;
                    } else {
                        vec1[s[slow++] - 'A']--;
                    }
                }
            }
            vec1[s[fast++] - 'A']++;
        }
        return s.substr(start, min_num);
    }
};

int main() {
    Solution s;
    string a = "ADOBECODEBANC";
    string b = "ABC";
    s.minWindow(a, b);
    return 0;
}