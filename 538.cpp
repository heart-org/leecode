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
    TreeNode *convertBST(TreeNode *root) {
        SearchTree(root);
        return root;
    }

private:
    int sum = 0;

    void SearchTree(TreeNode *Node) {
        if (Node == nullptr)
            return;
        SearchTree(Node->right);
        sum += Node->val;
        Node->val = sum;
        SearchTree(Node->left);
    }
};

int main() {
    Solution s;

    return 0;
}