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
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr && subRoot == nullptr)
            return true;
        else if (root == nullptr || subRoot == nullptr)
            return false;
        return (check(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }

private:
    bool check(TreeNode *Node, TreeNode *subNode) {
        if (Node == nullptr && subNode == nullptr)
            return true;
        else if (Node == nullptr || subNode == nullptr)
            return false;
        else if (Node->val != subNode->val)
            return false;
        else {
            return (check(Node->left, subNode->left) && check(Node->right, subNode->right));
        }
    }
};


int main() {
    Solution s;

    return 0;
}