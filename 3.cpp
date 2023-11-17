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
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 1)
            return 1;
        int res = 0;
        vector<char> x;
        int begin = 0;
        x.push_back(s[0]);
        for (int i = 1; i < s.length(); ++i) {
            char flag = s[i];
            for (int j = begin; j < x.size(); ++j) {
                if (flag == x[j]){
                    begin = ++j;
                    x.push_back(flag);
                    break;
                }
                if (j == x.size() - 1 && x[j] != flag){
                    x.push_back(flag);
                    break;
                }
            }
            int k = 0;
            for (int m = begin; m < x.size(); ++m) {
                k++;
            }
            res = res > k ? res : k;
        }
        return res;
    }
};

int main(){
    string s = " ";
    Solution leng;
    leng.lengthOfLongestSubstring(s);
    cout << s.length() << endl;



    return 0;
}