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

/*class Solution {
public:
    string reverseStr(string s, int k) {
        int x = 2 * k;
        int size = s.length() / x;
        if ((s.length() - size * x) < k)
            reverse(s.begin() + size * x, s.end());
        else{
            reverse(s.begin() + size * x, s.begin() + size * x + k);
        }
        int round = 0;
        while(size--){
            reverse(s.begin() + round * x, s.begin() + round * x + k);
            round++;
        }
        return s;
    }
};*/

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

int main() {
    Solution s;

    return 0;
}