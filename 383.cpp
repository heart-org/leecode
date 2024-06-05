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
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for (auto c: magazine) {
            map[c]++;
        }
        for (auto i: ransomNote) {
            if (map.find(i) == map.end() || map.find(i)->second == 0) {
                return false;
            }
            map[i]--;
        }
        return true;
    }
};

int main() {
    Solution s;

    return 0;
}