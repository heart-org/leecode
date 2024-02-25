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
    vector<int> partitionLabels(string s) {
        vector<int> res;
        int cover = search(s, s[0]);
        int start = 0;
        for (int i = 0; i < s.length(); ++i) {
            int cur_cover = search(s, s[i]);
            cover = max(cur_cover, cover);
            if (i == cover) {
                res.push_back(cover - start + 1);
                start = i + 1;
            }
        }
        return res;
    }

private:
    int search(string s, char a) {
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == a)
                res = i;
        }
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}