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

using vecContainer = vector<int>;
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int val) : val(val), next(nullptr) {}

    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void seq_traversal(TreeNode *cur, vecContainer &vec) {
    if (cur == nullptr)
        return;
    vec.emplace_back(cur->val);
    seq_traversal(cur->left, vec);
    seq_traversal(cur->right, vec);
}

class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> que1;
        if (root == nullptr)
            return res;
        que1.push(root);
        while (que1.size()) {
            int size = que1.size();
            res = que1.front()->val;
            while (size--) {
                if (que1.front()->left)
                    que1.push(que1.front()->left);
                if (que1.front()->right)
                    que1.push(que1.front()->right);
                que1.pop();
            }
        }
        return res;
    }

private:
    int res = 0;
};

int main() {
    Solution s;


    return 0;
}