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
    void reverseString(vector<char> &s) {
        /*int left = 0;
        int right = s.size() - 1;
        while (left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }*/
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; ++i, --j) {
            swap(s[i], s[j]);
        }
    }
};

int main() {
    Solution s;

    return 0;
}