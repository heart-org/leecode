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
    int getDepth(TreeNode *Node) {
        if (Node == nullptr)
            return 0;
        return 1 + max(getDepth(Node->left), getDepth(Node->right));
    }

    bool isBalanced(TreeNode *root) {
        if (root == nullptr)
            return true;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        return (abs(leftDepth - rightDepth) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};

/*
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        check(root);
        return flag;
    }

private:
    int sum = 0;
    bool flag = true;

    int check(TreeNode *Node) {
        if (Node == nullptr)
            return 0;
        int l_height = check(Node->left);
        int r_height = check(Node->right);
        if (abs(l_height - r_height) > 1)
            flag = false;
        return (l_height >= r_height ? l_height : r_height) + 1;
    }
};
*/

int main() {
    Solution s;

    return 0;
}