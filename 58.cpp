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

/*
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length() == 0){
            return 0;
        }
        int res =  0;
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length(); ++i) {
            if(res != 0 && isspace(s[i])){
                break;
            }
            if (!isspace(s[i])){
                res++;
            }
        }

        return res;
    }
};
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length() == 0){
            return 0;
        }
        int res = 0;
        int x = 0;
        for (int fast = 0; fast < s.length(); ++fast) {
            if (!isspace(s[fast])){
                x++;
                if(fast == s.length() - 1){
                    res = x;
                }
            }else{
                if (x == 0)
                    continue;
                else{
                    res = x;
                    x = 0;
                }
            }
        }
        return res;
    }
};

int main(){

    return 0;
}