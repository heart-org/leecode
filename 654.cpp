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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        if (nums.empty())
            return nullptr;
        return traversal(nums);
    }

private:
    TreeNode *traversal(vec_type vec) {
        if (vec.empty())
            return nullptr;
        int max_value = INT_MIN;
        int index = 0;
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] > max_value) {
                index = i;
                max_value = vec[index];
            }
        }
        TreeNode *root = new TreeNode(vec[index]);
        vec_type left_vec(vec.begin(), vec.begin() + index);
        vec_type right_vec(vec.begin() + index + 1, vec.end());

        root->left = traversal(left_vec);
        root->right = traversal(right_vec);
        return root;
    }
};

int main() {
    Solution s;


    return 0;
}