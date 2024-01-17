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
    bool isValidBST(TreeNode *root) {
        vec_type vec;
        transform_vec(root, vec);
        for (int i = 1; i < vec.size(); ++i) {
            if (vec[i - 1] >= vec[i])
                return false;
        }
        return true;
    }

    void transform_vec(TreeNode *Node, vec_type &vec) {
        if (Node == nullptr)
            return;
        transform_vec(Node->left, vec);
        vec.emplace_back(Node->val);
        transform_vec(Node->right, vec);
    }
};

int main() {
    Solution s;

    return 0;
}