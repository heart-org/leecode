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

using vec_type = vector<int>;

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty())
            return nullptr;
        return traversal(inorder, postorder);
    }

private:
    TreeNode *traversal(vec_type &inorder, vec_type &postorder) {
        if (postorder.empty())
            return nullptr;
        int root_value = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(root_value);
        if (inorder.size() == 1) {
            return root;
        }
        int index = 0;
        for (index; index < inorder.size(); ++index) {
            if (inorder[index] == root_value)
                break;
        }
        vec_type leftInorder(inorder.begin(), inorder.begin() + index);
        vec_type rightInorder(inorder.begin() + index + 1, inorder.end());
        postorder.resize(postorder.size() - 1);

        vec_type leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vec_type rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }
};

int main() {
    Solution s;

    return 0;
}