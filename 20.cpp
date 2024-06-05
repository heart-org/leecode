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

using namespace std;

/*
class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        if (s.size() % 2 != 0)
            return false;
        for (int i = 0; i < s.size(); ++i) {
            if (s1.empty()){
                s1.push(s[i]);
            }else{
                if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                    s1.push(s[i]);
                }else if (s1.top() == '(' && s[i] == ')'){
                    s1.pop();
                }else if(s1.top() == '[' && s[i] == ']'){
                    s1.pop();
                }else if (s1.top() == '{' && s[i] == '}'){
                    s1.pop();
                }else
                    return false;
            }
        }
        return s1.empty();
    }
};
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s.length() % 2 != 0)
            return false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(')');
            } else if (s[i] == '[') {
                st.push(']');
            } else if (s[i] == '{') {
                st.push('}');
            } else if (st.empty() || s[i] != st.top()) {
                return false;
            }else
                st.pop();
        }
        return st.empty();
    }
};

int main() {
    string s = "(]{}";
    Solution i;
    cout << s.length() << endl;
    i.isValid(s);

    return 0;
}