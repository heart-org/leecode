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
    int characterReplacement(string s, int k) {
        vector<int> num(26, 0);//用来记录字符个数
        int n = s.length();
        int maxlength = 0;
        int left = 0, right = 0;
        while (right < n) {
            num[s[right] - 'A']++;//当前字符个数+1
            maxlength = max(maxlength, num[s[right] - 'A']);//当前数量最多字符
            if (right - left + 1 - maxlength > k) {//当前窗口中数量-最多字符=非最多字符，判断非最多字符是否超过可以更改的数量k
                num[s[left] - 'A']--;//超过数量k，left++,整个窗口右移1位
                left++;
            }
            right++;
        }
        return right - left;
        //整个窗口是当前可以满足条件的数量，每次不满足时，整个窗口右移，所以窗口大小始终是最长字符
    }
};

int main(){
    string s = "AABABBA";
    Solution x;
    x.characterReplacement(s, 1);

    return 0;
}