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
#include "cctype"

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string x;
        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(tolower(s[i])) || isalpha(tolower(s[i]))) {
                x += tolower(s[i]);
            }
        }
        for (int i = 0; i < x.length(); ++i) {
            if (x[i] == x[x.length()-(i+1)]) {
                continue;
            }
            return false;
        }
        return true;
    }
};

int main(){
    string s = "A man, a plan, a canal: Panama";
    Solution().isPalindrome(s);

    return 0;
}