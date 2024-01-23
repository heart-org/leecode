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

using vecContainer = vector<int>;

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return searchBinaryTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *searchBinaryTree(vecContainer &vec, int left, int right) {
        if (left > right)
            return nullptr;
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(vec[mid]);
        root->left = searchBinaryTree(vec, left, mid - 1);
        root->right = searchBinaryTree(vec, mid + 1, right);
        return root;
    }
};

int main() {
    Solution s;

    return 0;
}