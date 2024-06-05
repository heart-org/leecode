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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using vecContainer = vector<double>;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vecContainer res;
        queue<TreeNode *> que1;
        que1.push(root);
        while (!que1.empty()) {
            int size = que1.size();
            double num1 = 0;
            int num2 = size;
            while (size--) {
                if (que1.front()->left)
                    que1.push(que1.front()->left);
                if (que1.front()->right)
                    que1.push(que1.front()->right);
                num1 += que1.front()->val;
                que1.pop();
            }
            res.emplace_back(num1 / num2);
        }
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}
