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

/*
using stackType = stack<int>;
void inOrder_record(TreeNode * Node, stackType &stack_set);
void inOrder_assign(TreeNode ** Node, stackType &stack_set);

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr || root->left == nullptr || root->right == nullptr)
            return root;
        stackType stack_set;
        inOrder_record(root, stack_set);
        inOrder_assign(&root, stack_set);

        return root;
    }
};

void inOrder_record(TreeNode * Node, stackType &stack_set){
    if (Node == nullptr)
        return;
    inOrder_record(Node->left, stack_set);
    stack_set.push(Node->val);
    inOrder_record(Node->right, stack_set);
}

void inOrder_assign(TreeNode ** Node, stackType &stack_set){
    if ((*Node) == nullptr)
        return;
    inOrder_assign(&(*Node)->left, stack_set);
    (*Node)->val = stack_set.top();
    stack_set.pop();
    inOrder_assign(&(*Node)->right, stack_set);
}
*/


class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr)
            return root;
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

int main() {
    Solution s;
    /*TreeNode * Node1 = new TreeNode{1};
    TreeNode * Node3 = new TreeNode{3};
    TreeNode * Node6 = new TreeNode{6};
    TreeNode * Node9 = new TreeNode{9};
    TreeNode * Node2 = new TreeNode{2, Node1, Node3};
    TreeNode * Node7 = new TreeNode{7, Node6, Node9};
    TreeNode * Node4 = new TreeNode{4, Node2, Node7};*/
    TreeNode *Node2 = new TreeNode{2};
    TreeNode *Node4 = new TreeNode{4, Node2, nullptr};
    s.invertTree(Node4);

    return 0;
}