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

using vecContainer = vector<int>;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vecContainer> res(n, vecContainer(n, 0));
        int startx = 0, starty = 0;
        int loop = n / 2;
        int mid = n / 2;
        int count = 1;
        int offset = 1;
        int i, j;
        while (loop--) {
            i = startx;
            j = starty;
            for (j; j < n - offset; ++j) {
                res[i][j] = count++;
            }
            for (i; i < n - offset; ++i) {
                res[i][j] = count++;
            }
            for (j; j > starty; --j) {
                res[i][j] = count++;
            }
            for (i; i > startx; --i) {
                res[i][j] = count++;
            }
            startx++;
            starty++;
            offset++;
        }
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}