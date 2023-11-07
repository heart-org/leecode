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

 void backTracking(int n, int k, int startIndex, vector<int> str,vector<vector<int>> &res){
     if (str.size() == k){
         res.push_back(str);
         return;
     }
     for (int i = startIndex; i <= n; ++i) {
         str.push_back(i);
         backTracking(n, k, i + 1,str, res);
         str.pop_back();
     }
 }

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int startIndex = 1;
        vector<vector<int>> res;
        vector<int> str;
        backTracking(n, k, startIndex, str, res);

        return res;
    }
};


int main(){
    Solution s;
    s.combine(4, 2);

    return 0;
}