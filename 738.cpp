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
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        int flag = str.size();
        for (int i = str.size() - 1; i > 0; --i) {
            if (str[i - 1] > str[i]) {
                str[i - 1]--;
                flag = i;
            }
        }
        for (int i = flag; i < str.size(); ++i) {
            str[i] = '9';
        }
        return stoi(str);
    }
};

int main() {
    Solution s;

    return 0;
}