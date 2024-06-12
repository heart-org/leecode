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
class Solution {
public:
    int getDepth(TreeNode * Node){
        if (Node == nullptr)
            return 0;
        int left_depth = getDepth(Node->left);
        int right_depth = getDepth(Node->right);
        int cur_depth;
        if (left_depth == 0 || right_depth == 0)
            cur_depth = max(left_depth, right_depth) + 1;
        else
            cur_depth = min(left_depth, right_depth) + 1;
        return cur_depth;
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return getDepth(root);
    }
};
*/

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left_Depth = minDepth(root->left);
        int right_Depth = minDepth(root->right);
        if (left_Depth == 0 || right_Depth == 0)
            return max(left_Depth, right_Depth) + 1;
        return min(left_Depth, right_Depth) + 1;
    }
};

int main() {
    Solution s;

    return 0;
}