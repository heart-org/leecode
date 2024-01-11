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
    int sumOfLeftLeaves(TreeNode *root) {
        add_leaves(root);
        return sum;
    }

private:
    void add_leaves(TreeNode *Node) {
        if (Node == nullptr) {
            return;
        }
        if (Node->left) {
            if (Node->left->left == nullptr && Node->left->right == nullptr)
                sum += Node->left->val;
            else
                add_leaves(Node->left);
        }
        add_leaves(Node->right);
    }

    int sum = 0;
};

int main() {
    Solution s;
    TreeNode *Node3 = new TreeNode(3);
    TreeNode *Node4 = new TreeNode(4);
    TreeNode *Node5 = new TreeNode(5);
    TreeNode *Node2 = new TreeNode(2, Node4, Node5);
    TreeNode *Node1 = new TreeNode(1, Node2, Node3);
    s.sumOfLeftLeaves(Node1);

    return 0;
}