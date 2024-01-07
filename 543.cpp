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

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        cal_depth(root);
        return max_depth;
    }

private:
    int max_depth = 0;

    int cal_depth(TreeNode *Node) {
        if (Node == nullptr)
            return 0;
        int l_depth = cal_depth(Node->left);
        int r_depth = cal_depth(Node->right);
        if (l_depth + r_depth > max_depth)
            max_depth = l_depth + r_depth;
        return max(l_depth, r_depth) + 1;
    }
};

int main() {
    Solution s;

    return 0;
}