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


//method1:有序数组
class Solution1 {
public:
    int getMinimumDifference(TreeNode *root) {
        vec_type vec;
        get_value(root, vec);
        sort(vec.begin(), vec.end());
        int result = INT_MAX;
        for (int i = 1; i < vec.size(); ++i) {
            result = min(result, vec[i] - vec[i - 1]);
        }
        return result;
    }

private:
    void get_value(TreeNode *Node, vec_type &vec) {
        if (Node == nullptr)
            return;
        vec.emplace_back(Node->val);
        get_value(Node->left, vec);
        get_value(Node->right, vec);
    }
};

//method2:双指针
class Solution {
public:
    int getMinimumDifference(TreeNode *root) {
        traversal(root);
        return result;
    }

private:
    int result = INT_MAX;
    TreeNode *pre = nullptr;

    void traversal(TreeNode *cur) {
        if (cur == nullptr)
            return;
        traversal(cur->left);
        if (pre != nullptr)
            result = min(result, cur->val - pre->val);
        pre = cur;
        traversal(cur->right);
    }
};

int main() {
    Solution s;

    return 0;
}