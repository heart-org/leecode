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

 void backTracking(int n, int left, int right,vector<string> &res, string str){
    if (right > left)
        return;
    if (right == n && left == n)
        res.push_back(str);
    if (left < n){
        str += "(";
        backTracking(n, left + 1, right, res, str);
        str.pop_back();
    }
    if (right < n){
        str += ")";
        backTracking(n, left, right + 1, res, str);
        str.pop_back();
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int left = 0;
        int right = 0;
        vector<string> res;
        string str = "";
        backTracking(n,left,right,res,str);

        return res;
    }
        
};

int main(){

    return 0;
}