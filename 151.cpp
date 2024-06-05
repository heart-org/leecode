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
    string reverseWords(string s) {
        stack<string> st;
        string str;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                if (str.size() == 0)
                    continue;
                else {
                    st.push(str);
                    str.clear();
                }
            } else {
                str.push_back(s[i]);
            }
        }
        if (!str.empty())
            st.push(str);
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
            if (!st.empty())
                res += ' ';
        }
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}