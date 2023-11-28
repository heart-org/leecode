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
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length())
            return false;
        vector<int> vec1(26, 0);
        vector<int> vec2(26, 0);
        int slow = 0;
        for (int i = 0; i < s1.length(); ++i) {
            vec1[s1[i] - 'a']++;
            vec2[s2[i] - 'a']++;
        }
        for (int fast = s1.length(); fast < s2.length(); ++fast) {
            if(equal(vec1.begin(), vec1.end(),vec2.begin())){
                return true;
            }else{
                vec2[s2[fast] - 'a']++;
                vec2[s2[slow++] - 'a']--;
            }
        }
        if(equal(vec1.begin(), vec1.end(),vec2.begin())){
            return true;
        }
        return false;
    }
};
int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";
    Solution s;
    s.checkInclusion(s1, s2);

    return 0;
}