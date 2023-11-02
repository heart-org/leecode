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

using namespace std;

class Solution {
public:
    string encode(vector<string> &strs) {
        string input_str;
        for (int i = 0; i < strs.size(); ++i) {
            for (int j = 0; j < strs[i].size(); ++j) {
                if (strs[i][j] != '/') {
                    input_str += strs[i][j];
                } else
                    input_str += "//";
            }
            input_str += "/s";
        }
        return input_str;
    }

    vector<string> decode(string &str) {
        vector<string> output_str;
        string count_str;
        bool count = false;
        for (int i = 0; i < str.length(); i++) {
            if (count) {
                if (str[i] == 's') {
                    output_str.push_back(count_str);
                    count_str.clear();
                } else {
                    count_str += '/';
                }
                count = false;
                continue;
            }
            if (str[i] == '/') {
                count = true;
            } else
                count_str += str[i];

        }
        return output_str;
    }
};


int main() {
    vector<string> strs = {"lint", "code", "love", "you"};
    string input_str = Solution().encode(strs);
    Solution().decode(input_str);


    return 0;
}
