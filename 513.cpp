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
//递归
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return res;
    }
private:
    void traversal(TreeNode * Node, int depth){
        if (Node->left == nullptr && Node->right == nullptr) {
            if (depth > maxDepth) {
                maxDepth = depth;
                res = Node->val;
            }
            return;
        }
        if (Node->left) {
            traversal(Node->left, depth + 1);
        }
        if (Node->right) {
            traversal(Node->right, depth + 1);
        }
        return;
    }
    int maxDepth = INT_MIN;
    int res = 0;
};
*/

//层序遍历
using que_type = queue<TreeNode *>;

class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        que_type queue1;
        int res = 0;
        queue1.push(root);
        while (!queue1.empty()) {
            int size = queue1.size();
            res = queue1.front()->val;
            for (int i = 0; i < size; ++i) {
                TreeNode *Node = queue1.front();
                queue1.pop();
                if (Node->left)
                    queue1.push(Node->left);
                if (Node->right)
                    queue1.push(Node->right);
            }
        }
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}