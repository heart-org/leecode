#include <iostream>
using namespace std;
#include <algorithm>

class Solution {
public:
    bool isAnagram(string s, string t) {
        //方法一
        /*
        if (s.length() != t.length())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s == t)
            return true;
        else
            return false;
    }
        */
        //方法二
        int i;
        int arr[26] = {0};
        for (i = 0; i < s.size(); i++) {
            arr[s[i] - 'a']++;
        }
        for(i= 0; i < t.size(); i++){
            arr[t[i] - 'a']--;
        }
        for(i = 0; i < 26; i++){
            if (arr[i] != 0)
                return false;
        }
        return true;
    }
};

int main(){
    Solution S;
    S.isAnagram("anang", "gnana");

    return 0;
}