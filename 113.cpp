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
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr)
            return res;
        sumNode(root, targetSum, vec, sum);
        return res;
    }

private:
    void sumNode(TreeNode *Node, int target, vector<int> vec, int sum) {
        if (Node == nullptr)
            return;
        sum += Node->val;
        vec.emplace_back(Node->val);
        if (Node->left == nullptr && Node->right == nullptr && sum == target) {
            res.emplace_back(vec);
            return;
        }
        sumNode(Node->left, target, vec, sum);
        sumNode(Node->right, target, vec, sum);
    }

    int sum = 0;
    vector<vector<int>> res;
    vector<int> vec;
};

int main() {
    Solution s;

    return 0;
}