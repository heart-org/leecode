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
    string minWindow(string s, string t) {
        int t_hash[26];
        int s_hash[26];
        string res;
        //存所有t的hash
        for (int i = 0; i < t.length(); ++i) {
            t_hash[t[i] - 'A']++;
            s_hash[s[i] - 'A']++;
        }
        int slow, fast;
        slow = 0;
        fast = t.length();
        int flag = true;
        int sum = INT_MAX;
        while (fast < t.length()) {
            for (auto i: s_hash) {
                if (t_hash[i] == 0 || t_hash[i] == s_hash[i])
                    continue;
                else {
                    flag = false;//不满足继续增大窗口
                    break;
                }
            }
            if (!flag) {
                s_hash[s[fast++] - 'A']++;
            } else {
                sum = min(sum, fast - slow);
                s_hash[s[slow++] - 'A']--;
                s_hash[s[slow] - 'A']++;
            }
            flag = true;
        }
        while (fast - slow > t.length()) {
            s_hash[s[slow++] - 'A']--;
            s_hash[s[slow] - 'A']++;
            for (auto i: s_hash) {
                if (t_hash[i] == 0 || t_hash[i] == s_hash[i])
                    continue;
                else {
                    return sum;
                }
            }
            sum = min(sum, fast - slow);
        }


    }
};

int main() {

    return 0;
}