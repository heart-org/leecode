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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vecContainer res;
        if (root == nullptr)
            return res;
        queue<TreeNode *> que1;
        que1.push(root);
        while (!que1.empty()) {
            int size = que1.size();
            while (size--) {
                if (que1.front()->left)
                    que1.push(que1.front()->left);
                if (que1.front()->right)
                    que1.push(que1.front()->right);
                if (size == 0)
                    res.emplace_back(que1.front()->val);
                que1.pop();
            }
        }
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}