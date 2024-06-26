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

using namespace std;

/*
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> s1;
        for (int i = 0; i < s.size(); ++i) {
            if (s1.empty()){
                s1.push(s[i]);
            }else{
                if (s1.top() == s[i]){
                    s1.pop();
                }else{
                    s1.push(s[i]);
                }
            }
        }
        string res;
        while(!s1.empty()){
            res += s1.top();
            s1.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
*/



class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); ++i) {
            if (!st.empty()){
                if (s[i] == st.top()){
                    st.pop();
                }else
                    st.push(s[i]);
            }else
                st.push(s[i]);
        }
        string res;
        if (!st.empty()){
            while(!st.empty()){
                res += st.top();
                st.pop();
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){

    return 0;
}