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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr)
            return false;
        sumNode(root, targetSum, sum);
        return flag;
    }

private:
    void sumNode(TreeNode *Node, int target, int sum) {
        if (Node == nullptr)
            return;
        sum += Node->val;
        if (Node->left == nullptr && Node->right == nullptr && sum == target)
            flag = true;
        sumNode(Node->left, target, sum);
        sumNode(Node->right, target, sum);

    }

    int sum = 0;
    bool flag = false;
};

int main() {
    Solution s;

    return 0;
}