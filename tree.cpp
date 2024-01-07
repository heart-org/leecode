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

//树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

//先序遍历
void preOrder(TreeNode *Node) {
    if (Node == nullptr)
        return;
    cout << Node->val << " ";
    preOrder(Node->left);
    preOrder(Node->right);
}

//中序遍历
void inOrder(TreeNode *Node) {
    if (Node == nullptr)
        return;
    inOrder(Node->left);
    cout << Node->val << " ";
    inOrder(Node->right);
}

//后序遍历
void posOrder(TreeNode *Node) {
    if (Node == nullptr)
        return;
    posOrder(Node->left);
    posOrder(Node->right);
    cout << Node->val << " ";
}


int main() {

    return 0;
}