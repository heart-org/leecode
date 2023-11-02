#include<iostream>
#include<map>
#include<string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> ans;
        map<string , vector<string>> m;
        for (auto&j:strs) {
//            string X(26, 0);
//            for(const auto&c:j){
//                X[c - 'a']++;
//            }
            string v = j;
            sort(v.begin(),v.end());
            m[v].push_back(j);
        }
        for(const auto&a: m)
        {
            ans.push_back(a.second);
        }
        return ans;
    }
};

int main(){
    Solution S;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat", "zaq", "baz"};
    S.groupAnagrams(strs);

    return 0;
}